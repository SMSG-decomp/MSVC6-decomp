c1_token * __fastcall token_next(int *reader)

{
  byte bVar1;
  int iVar2;
  c1_token *pcVar3;
  fe_name *pfVar4;
  c1_token *pcVar5;
  fe_arena *a;
  
  pcVar5 = (c1_token *)(**(code **)**(undefined4 **)reader[1])();
  bVar1 = pcVar5->code;
  if (bVar1 < 0xf2) {
    return pcVar5;
  }
  do {
    if (bVar1 == 0xf2) {
      *reader = (int)(pcVar5->value).ptr;
      if ((g_compile_flags_c4 & 0x200000) != 0) {
        return pcVar5;
      }
      if (((g_compile_flags_c4 & 0x20000) != 0) && ((g_compile_flags_c4 & 0x20) == 0)) {
        il_emit_pragma_or_segment_record(0x24);
      }
    }
    else if (bVar1 == 0xf7) {
      iVar2 = reader[1];
      if (*(int *)(iVar2 + 0xc) != 1) {
        return pcVar5;
      }
      if (iVar2 != 0) {
        reader[1] = *(int *)(iVar2 + 4);
        *reader = *(int *)(iVar2 + 8);
        if (*(code **)(iVar2 + 0x10) != (code *)0x0) {
          (**(code **)(iVar2 + 0x10))();
        }
      }
    }
    else if ((&g_token_class)[bVar1] == -10) {
      switch(g_last_name->keyword_class) {
      case '\x01':
        diag_warning(1,0xe2,g_last_name);
        break;
      case '\x02':
        diag_warning(1,0xe9,g_last_name);
        break;
      case '\x03':
        diag_warning(1,0xea,g_last_name);
        break;
      case '\x04':
        diag_warning(1,0xeb,g_last_name);
        break;
      case '\x05':
        diag_warning(1,0xec,g_last_name);
        break;
      case '\x06':
        if (g_ms_extensions == '\0') {
          diag_error(0x148,g_last_name);
        }
        else {
          diag_warning(1,0xed);
        }
        if (g_token_arena_index == 0) {
          if (g_pool_default.left < 0x20) {
            pool_reserve(&g_pool_default,0x20);
          }
          g_pool_default.left = g_pool_default.left - 0x20;
          pcVar5 = (c1_token *)g_pool_default.cur;
          g_pool_default.cur = g_pool_default.cur + 0x20;
        }
        else {
          a = g_arenas + g_token_arena_index;
          pcVar5 = (c1_token *)a->cur;
          pcVar3 = (c1_token *)g_arenas[g_token_arena_index].end;
          a->cur = &pcVar5[1].code;
          if (pcVar3 < pcVar5 + 1) {
            arena_grow(a);
          }
        }
        pfVar4 = g_last_name;
        if (pcVar5 != (c1_token *)0x0) {
          pcVar5->code = '\x06';
          (pcVar5->value).name = pfVar4;
          (pcVar5->value).words[1] = g_token_position;
          return pcVar5;
        }
        return (c1_token *)0x0;
      }
    }
    else {
      if (bVar1 != 0xf4) {
        return pcVar5;
      }
      pcVar5 = (c1_token *)pragma_process_saved_tokens(pcVar5);
      if (pcVar5 != (c1_token *)0x0) {
        pcVar5 = token_next_fragment(pcVar5);
        return pcVar5;
      }
    }
    pcVar5 = (c1_token *)(**(code **)**(undefined4 **)reader[1])();
    bVar1 = pcVar5->code;
    if (bVar1 < 0xf2) {
      return pcVar5;
    }
  } while( true );
}

