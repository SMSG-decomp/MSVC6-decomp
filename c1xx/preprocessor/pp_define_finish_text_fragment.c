void pp_define_finish_text_fragment(void)

{
  uchar *unaff_EBP;
  char *in_stack_00000014;
  
  name_intern(in_stack_00000014);
  if (unaff_EBP != g_macro_text_buffer) {
    if (g_macro_text_buffer_limit <= unaff_EBP) {
      pp_define_check_size
                ((uint)unaff_EBP,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
    }
    *unaff_EBP = '\0';
    unaff_EBP[1] = 'D';
    pp_define_finish(g_macro_text_buffer,(uint)(unaff_EBP + 1 + (1 - (int)g_macro_text_buffer)),0);
    return;
  }
  pp_define_finish((c1_u8 *)0x0,0,0);
  return;
}

