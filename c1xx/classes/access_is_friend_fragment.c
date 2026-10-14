int __cdecl
access_is_friend_fragment
          (c1_symbol *friend_sym,int *friend_entry,c1_symbol *tmpl,int result,c1_symbol *sym_class,
          c1_symbol *func)

{
  c1_symbol *friend_sym_00;
  int iVar1;
  
  if (friend_sym == tmpl) {
    iVar1 = access_is_friend_template_match(friend_entry,tmpl,sym_class,func);
    return iVar1;
  }
  while ((friend_entry = (int *)friend_entry[2], result == 0 && (friend_entry != (int *)0x0))) {
    friend_sym_00 = (c1_symbol *)friend_entry[1];
    if ((friend_sym_00->kind & 0x1f) == 4) {
      if ((sym_class != (c1_symbol *)0x0) && (friend_sym_00 == sym_class)) {
        result = 1;
      }
    }
    else if (func != (c1_symbol *)0x0) {
      if (friend_sym_00 == func) {
        result = 2;
      }
      else if (tmpl != (c1_symbol *)0x0) {
        iVar1 = access_is_friend_fragment(friend_sym_00,friend_entry,tmpl,0,sym_class,func);
        return iVar1;
      }
    }
  }
  return result;
}

