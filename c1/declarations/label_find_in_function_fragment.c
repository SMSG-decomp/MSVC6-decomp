c1_symbol * __cdecl label_find_in_function_fragment(void *label_name,void *name,c1_symbol *label)

{
  int iVar1;
  c1_symbol *pcVar2;
  c1_sym_link *link;
  
  iVar1 = str_compare_nocase(*(char **)((int)name + 4),*(char **)((int)label_name + 4));
  if (iVar1 == 0) {
    pcVar2 = label_find_in_function_fragment_2(label);
    return pcVar2;
  }
  do {
    link = label->next;
    if ((link == (c1_sym_link *)0x0) ||
       (label = (c1_symbol *)&link[-1].position, label == (c1_symbol *)0x0)) {
      return (c1_symbol *)0x0;
    }
    if (link->name == name) {
      return label;
    }
  } while ((link[1].type != (c1_type *)0x0) || (((uint)link[-1].type & 0x10) == 0));
  pcVar2 = label_find_in_function_fragment(link->name,name,label);
  return pcVar2;
}

