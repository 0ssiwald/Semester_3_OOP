#ifndef CLIST_H_INCLUDED
#define CLIST_H_INCLUDED

template<class T> class CList
{
   private:
      struct ListElement
      {
         T Data;
         ListElement *Next, *Prev;
         ListElement(): Next(nullptr), Prev(nullptr) // Konstruktur
         { }
      };

      ListElement *First, *Last;
      unsigned Anzahl;

   public:
      CList();                // Konstruktor
      CList(const CList&);    // Kopierkonstruktor
      virtual ~CList();       // Destruktor

      CList& operator=(const CList&);

      bool empty() const { return Anzahl == 0; }
      unsigned size() const { return Anzahl; }

      // am Anfang bzw. Ende einfügen
      void push_front(const T&);
      void push_back(const T&);

      // am Anfang bzw. Ende entnehmen
      void pop_front();
      void pop_back();

      // am Anfang bzw. Ende lesen
      T& front();
      const T& front() const;
      T& back();
      const T& back() const;

      // ========================================
      // Jetzt kommt die geschachtelte
      // Klasse fuer den iterator:
      class iterator
      {
         private:
            ListElement* aktuell;   // Zeiger auf
                                    // aktuelles Element
         public:
            friend class CList<T>;  // wg. erase-Zugriff
                                    // auf aktuell
            iterator(ListElement* Init = NULL)
            : aktuell(Init)
            { }

            iterator(const CList& L)
            {  *this = L.begin(); }

            //Dereferenzierung:
            const T& operator*() const
            {  return aktuell->Data; }

            T& operator*()
            {  return aktuell->Data; }

            iterator& operator++() // prefix
            {
               if (aktuell)
                  aktuell = aktuell->Next;
               return *this;
            }

            iterator operator++(int) // postfix
            {
               iterator temp = *this;
               ++*this;
               return temp;
            }

            bool operator==(const iterator& x) const
            {  return aktuell == x.aktuell; }

            bool operator!=(const iterator& x) const
            {  return aktuell != x.aktuell; }

      }; // iterator
      // Hier ist Deklaration und Definition
      // des Iterators zu Ende!
      // ========================================

      // Methoden der Klasse CList,
      // die die Klasse iterator benutzen:

      iterator begin() const
      {  return iterator(First); }

      iterator end() const
      {  return iterator(); } // NULL-iterator

      void erase(iterator& pos) // Element löschen
      {
         if (pos.aktuell == First)
         {
            pop_front();
            pos.aktuell = First; // neuer Anfang
         }
         else
            if (pos.aktuell == Last)
            {
               pop_back();
               pos.aktuell = Last;
            }
            else
            {
               // zwischen 2 Elementen ausketten
               pos.aktuell->Next->Prev = pos.aktuell->Prev;
               pos.aktuell->Prev->Next = pos.aktuell->Next;
               ListElement *temp = pos.aktuell;
               pos.aktuell = pos.aktuell->Next;
               delete temp;
               Anzahl--;
            }
      }

      // Vor pos einfuegen
      iterator insert(iterator pos, const T& Wert)
      {
         if (pos == begin())
         {
            push_front(Wert);
            return iterator(First);
         }
         if (pos == end())
         {
            push_back(Wert);
            return iterator(Last);
         }
         // zwischen 2 Elementen einketten
         ListElement *temp = new ListElement;
         temp->Data = Wert;
         temp->Next = pos.aktuell;
         temp->Prev = pos.aktuell->Prev;
         pos.aktuell->Prev->Next = temp;
         pos.aktuell->Prev = temp;
         Anzahl++;
         return iterator(temp);
      }
};

// ===== Implementierung der Klasse CList =====
// soweit nicht schon geschehen

template<class T>           // Konstruktor
inline CList<T>::CList()
: First(NULL), Last(NULL), Anzahl(0)
{ }

template<class T>           // Kopierkonstruktor
inline CList<T>::CList(const CList<T>& L)
: First(NULL), Last(NULL), Anzahl(0)
{
   ListElement *temp = L.Last;
   while (temp)
   {
      push_front(temp->Data);
      temp = temp->Prev;
   }
}

template<class T>           // Destruktor
inline CList<T>::~CList()
{
   while (!empty())
      pop_front();
}

template<class T>           // Zuweisungsoperator
inline CList<T>& CList<T>::operator=(const CList<T>& L)
{
   if (this != &L) // Selbstzuweisung ausschließen
   {
      while (!empty())
         pop_front(); // alles löschen
      // ... und neu aufbauen
      ListElement *temp = L.Last;
      while (temp)
      {
         push_front(temp->Data);
         temp = temp->Prev;
      }
   }
   return *this;
}

template<class T>
inline void CList<T>::push_front(const T& Dat)
{
   ListElement *temp = new ListElement;
   temp->Data = Dat;
   temp->Prev = NULL;
   temp->Next = First;
   if (!First)
      Last=temp; // einziges Element
   else
      First->Prev = temp;
   First = temp;
   Anzahl++;
}

template<class T>
inline void CList<T>::push_back(const T& Dat)
{
   ListElement *temp = new ListElement;
   temp->Data = Dat;
   temp->Prev = Last;
   temp->Next = NULL;
   if (!Last)
      First = temp; // einziges Element
   else
      temp->Prev->Next = temp;
   Last = temp;
   Anzahl++;
}

template<class T>
inline void CList<T>::pop_front()
{
//   assert(!empty());
   ListElement *temp = First;
   First = temp->Next;
   if (!First)
      // d.h. kein weiteres Element vorhanden
      Last = NULL;
   else
      First->Prev = NULL;
   delete temp;
   Anzahl--;
}

template<class T>
inline void CList<T>::pop_back()
{
   assert(!empty());
   ListElement *temp = Last;
   Last = temp->Prev;
   if (!Last)
      // d.h. kein weiteres Element vorhanden
      First = NULL;
   else
      Last->Next = NULL;
   delete temp;
   Anzahl--;
}

template<class T>
inline T& CList<T>::front()
{
   assert(!empty());
   return First->Data;
}

template<class T>
inline const T& CList<T>::front() const
{
   assert(!empty());
   return First->Data;
}

template<class T>
inline T& CList<T>::back()
{
   assert(!empty());
   return Last->Data;
}

template<class T>
inline const T& CList<T>::back() const
{
   assert(!empty());
   return Last->Data;
}


#endif // CLIST_H_INCLUDED
