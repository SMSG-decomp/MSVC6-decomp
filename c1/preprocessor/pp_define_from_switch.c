void __cdecl pp_define_from_switch(byte *s)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *cursor;
  byte *cursor_00;
  
  cursor = g_macro_text_buffer;
  bVar1 = *s;
  pbVar5 = s;
  while (bVar1 != 0) {
    if (g_char_class[bVar1] == '#') {
      pbVar5 = pbVar5 + 1;
    }
    else if (bVar1 == 0x3d) break;
    pbVar4 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar4;
  }
  if (*pbVar5 == 0x3d) {
    pbVar4 = (byte *)0x0;
    pbVar5 = pbVar5 + 1;
    pbVar2 = arena_alloc_copy(s,3,(int)pbVar5 - (int)s);
    pbVar5[(int)(pbVar2 + (-1 - (int)s))] = 0;
    cursor_00 = cursor;
    s = pbVar2;
    if (*pbVar5 != 0) {
      do {
        if (g_macro_text_buffer_limit <= cursor) {
          pp_define_check_size
                    ((uint)cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
        }
        *cursor = *pbVar5;
        cursor_00 = cursor + 1;
        if (g_char_class[*pbVar5] == '#') {
          pbVar4 = pbVar5 + 1;
          pbVar5 = pbVar5 + 1;
          *cursor_00 = *pbVar4;
          cursor_00 = cursor + 2;
pp_define_from_switch_copy_value_loop:
          pbVar4 = (byte *)0x0;
        }
        else {
          iVar3 = isspace((uint)*pbVar5);
          if (iVar3 == 0) goto pp_define_from_switch_copy_value_loop;
          if (pbVar4 == (byte *)0x0) {
            pbVar4 = cursor_00;
          }
        }
        pbVar2 = pbVar5 + 1;
        pbVar5 = pbVar5 + 1;
        cursor = cursor_00;
      } while (*pbVar2 != 0);
      if (pbVar4 != (byte *)0x0) {
        pp_define_finish_text_fragment(pbVar4);
        return;
      }
    }
  }
  else {
    if (g_macro_text_buffer_limit <= g_macro_text_buffer) {
      pp_define_check_size
                ((uint)g_macro_text_buffer,(int)g_macro_text_buffer,
                 (int *)&g_macro_text_buffer_limit);
    }
    *cursor = '1';
    cursor_00 = cursor + 1;
  }
  name_intern((char *)s);
  if (cursor_00 != g_macro_text_buffer) {
    if (g_macro_text_buffer_limit <= cursor_00) {
      pp_define_check_size
                ((uint)cursor_00,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
    }
    *cursor_00 = 0;
    cursor_00[1] = 0x44;
    pp_define_finish(g_macro_text_buffer,(uint)(cursor_00 + 1 + (1 - (int)g_macro_text_buffer)),0);
    return;
  }
  pp_define_finish((c1_u8 *)0x0,0,0);
  return;
}

