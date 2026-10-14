int __cdecl func_has_unreferenced_label(void)

{
  c1_symbol *pcVar1;
  
  pcVar1 = g_function_labels;
  while( true ) {
    if (pcVar1 == (c1_symbol *)0x0) {
      return 0;
    }
    if (((pcVar1->flags2 & 4) == 0) && ((pcVar1->detail).cls == (c1_class_record *)0x0)) break;
    if (pcVar1->next == (c1_symbol *)0x0) {
      return 0;
    }
    pcVar1 = (c1_symbol *)(&pcVar1->next[-1].tail.tparam_value + 1);
  }
  return CONCAT31((int3)((uint)pcVar1 >> 8),1);
}

