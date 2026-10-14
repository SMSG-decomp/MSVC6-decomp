void class_end_member_list(void)

{
  c1_class_record *pcVar1;
  
  pcVar1 = ((g_class_def_stack[g_class_depth].cls)->detail).cls;
  pcVar1->layout_flags3c = pcVar1->layout_flags3c | 4;
  if ((g_compile_flags_cc & 0x100000) == 0) {
    class_layout_direct_bases(g_class_def_stack[g_class_depth].cls);
    class_note_pragma_vtordisp_off();
    class_finish_layout_flags(g_class_def_stack[g_class_depth].cls);
  }
  return;
}

