void __cdecl class_note_pragma_vtordisp_off(void)

{
  g_class_vtordisp_off = g_class_vtordisp_off | g_pragma_vtordisp == 0;
  return;
}

