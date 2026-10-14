c1_symbol * __cdecl class_current_member_lookup(void *name)

{
  c1_sym_list *pcVar1;
  c1_sym_link *pcVar2;
  
  if (((*(uint *)((int)name + 8) & 0x40000) != 0) && (name != g_name_alignment_member)) {
    pcVar1 = ((g_class_def_stack[g_class_depth].cls)->x28).members;
    if (pcVar1 == (c1_sym_list *)0x0) {
      pcVar2 = (c1_sym_link *)0x0;
    }
    else {
      pcVar2 = pcVar1->head;
    }
    for (; pcVar2 != (c1_sym_link *)0x0; pcVar2 = pcVar2->next) {
      if (pcVar2->name == name) {
        return (c1_symbol *)&pcVar2[-1].position;
      }
      if (pcVar2 == (c1_sym_link *)0x0) {
        return (c1_symbol *)0x0;
      }
    }
  }
  return (c1_symbol *)0x0;
}

