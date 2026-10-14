int __cdecl
access_is_friend_template_match
          (int *friend_entry,c1_symbol *tmpl,c1_symbol *sym_class,c1_symbol *func)

{
  c1_symbol *friend_sym;
  int iVar1;
  
  do {
    iVar1 = 2;
    while( true ) {
      do {
        while( true ) {
          friend_entry = (int *)friend_entry[2];
          if ((iVar1 != 0) || (friend_entry == (int *)0x0)) {
            return iVar1;
          }
          friend_sym = (c1_symbol *)friend_entry[1];
          if ((friend_sym->kind & 0x1f) != 4) break;
          if ((sym_class != (c1_symbol *)0x0) && (friend_sym == sym_class)) {
            iVar1 = 1;
          }
        }
      } while (func == (c1_symbol *)0x0);
      if (friend_sym == func) break;
      if (tmpl != (c1_symbol *)0x0) {
        iVar1 = access_is_friend_fragment(friend_sym,friend_entry,tmpl,0,sym_class,func);
        return iVar1;
      }
    }
  } while( true );
}

