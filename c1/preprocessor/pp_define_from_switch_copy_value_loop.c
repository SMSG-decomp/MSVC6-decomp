void __cdecl pp_define_from_switch_copy_value_loop(void *is_space,byte *cursor,byte *text)

{
  int iVar1;
  byte *trailing_space;
  byte *pbVar2;
  byte *cursor_00;
  char *in_stack_00000014;
  
code_r0x10614cc5:
  do {
    trailing_space = (byte *)0x0;
    pbVar2 = text;
    cursor_00 = cursor;
    while( true ) {
      text = pbVar2 + 1;
      if (pbVar2[1] == 0) {
        if (trailing_space != (byte *)0x0) {
          pp_define_finish_text_fragment(trailing_space);
          return;
        }
        name_intern(in_stack_00000014);
        if (cursor_00 == g_macro_text_buffer) {
          pp_define_finish((c1_u8 *)0x0,0,0);
          return;
        }
        if (g_macro_text_buffer_limit <= cursor_00) {
          pp_define_check_size
                    ((uint)cursor_00,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
        }
        *cursor_00 = 0;
        cursor_00[1] = 0x44;
        pp_define_finish(g_macro_text_buffer,(uint)(cursor_00 + 1 + (1 - (int)g_macro_text_buffer)),
                         0);
        return;
      }
      if (g_macro_text_buffer_limit <= cursor_00) {
        pp_define_check_size
                  ((uint)cursor_00,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
      }
      *cursor_00 = *text;
      cursor = cursor_00 + 1;
      if (g_char_class[*text] == '#') break;
      iVar1 = (*is_space)((uint)*text);
      if (iVar1 == 0) goto code_r0x10614cc5;
      pbVar2 = text;
      cursor_00 = cursor;
      if (trailing_space == (byte *)0x0) {
        trailing_space = cursor;
      }
    }
    text = pbVar2 + 2;
    *cursor = pbVar2[2];
    cursor = cursor_00 + 2;
  } while( true );
}

