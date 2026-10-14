int __cdecl label_find_in_function(int name)

{
  c1_symbol *pcVar1;
  int iVar2;
  
  pcVar1 = g_function_labels;
  if (g_error_count == 0) {
    for (; pcVar1 != (c1_symbol *)0x0; pcVar1 = (c1_symbol *)((int)&pcVar1->next[-1].tail + 4)) {
      if ((pcVar1->name == (fe_name *)name) ||
         ((((pcVar1->detail).cls == (c1_class_record *)0x0 && ((pcVar1->flags5 & 0x10) != 0)) &&
          (iVar2 = str_compare_nocase(*(char **)(name + 4),pcVar1->name->text), iVar2 == 0)))) {
        return (int)pcVar1;
      }
      if (pcVar1->next == (c1_symbol *)0x0) {
        return 0;
      }
    }
  }
  return 0;
}

