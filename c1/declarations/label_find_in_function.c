c1_symbol * __cdecl label_find_in_function(void *name)

{
  c1_symbol *pcVar1;
  
  pcVar1 = g_function_labels;
  if (g_error_count == 0) {
    for (; pcVar1 != (c1_symbol *)0x0; pcVar1 = (c1_symbol *)&pcVar1->next[-1].position) {
      if (pcVar1->name == name) {
        return pcVar1;
      }
      if ((pcVar1->detail == (void *)0x0) && ((pcVar1->flags4 & 0x10) != 0)) {
        pcVar1 = label_find_in_function_fragment(pcVar1->name,name,pcVar1);
        return pcVar1;
      }
      if (pcVar1->next == (c1_sym_link *)0x0) {
        return (c1_symbol *)0x0;
      }
    }
  }
  return (c1_symbol *)0x0;
}

