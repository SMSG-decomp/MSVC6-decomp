void __cdecl pp_define_finish_text_fragment(byte *trailing_space)

{
  char *in_stack_00000014;
  
  name_intern(in_stack_00000014);
  if (trailing_space != g_macro_text_buffer) {
    if (g_macro_text_buffer_limit <= trailing_space) {
      pp_define_check_size
                ((uint)trailing_space,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
    }
    *trailing_space = 0;
    trailing_space[1] = 0x44;
    pp_define_finish(g_macro_text_buffer,(uint)(trailing_space + 1 + (1 - (int)g_macro_text_buffer))
                     ,0);
    return;
  }
  pp_define_finish((c1_u8 *)0x0,0,0);
  return;
}

