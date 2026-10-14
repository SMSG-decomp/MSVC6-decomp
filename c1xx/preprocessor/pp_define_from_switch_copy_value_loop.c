void __cdecl
pp_define_from_switch_copy_value_loop(void *is_space,byte *cursor,byte *value,char *name)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *cursor_00;
  
code_r0x104477d3:
  do {
    pbVar2 = (byte *)0x0;
    pbVar3 = value;
    cursor_00 = cursor;
    while( true ) {
      value = pbVar3 + 1;
      if (pbVar3[1] == 0) {
        if (pbVar2 != (byte *)0x0) {
          pp_define_finish_text_fragment();
          return;
        }
        name_intern(name);
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
      *cursor_00 = *value;
      cursor = cursor_00 + 1;
      if (g_char_class[*value] == '#') break;
      iVar1 = (*is_space)((uint)*value);
      if (iVar1 == 0) goto code_r0x104477d3;
      pbVar3 = value;
      cursor_00 = cursor;
      if (pbVar2 == (byte *)0x0) {
        pbVar2 = cursor;
      }
    }
    value = pbVar3 + 2;
    *cursor = pbVar3[2];
    cursor = cursor_00 + 2;
  } while( true );
}

