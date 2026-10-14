int __cdecl optrec_list_any_match(optrec *list,optrec *pats)

{
  int match;
  optrec *pat;
  
  do {
    pat = pats;
    if (list == (optrec *)0x0) {
      return 0;
    }
    for (; pat != (optrec *)0x0; pat = pat->next) {
      match = optrec_matches(list,pat);
      if (match != 0) {
        return 1;
      }
    }
    list = list->next;
  } while( true );
}

