byte * __fastcall token_next(c1_token_reader *reader)

{
  byte bVar1;
  c1xx_token_stream *pcVar2;
  c1_token_source_frame *pcVar3;
  byte *pbVar4;
  fe_name *pfVar5;
  bool bVar6;
  byte *pbVar7;
  c1_arena *a;
  
  pcVar2 = reader->top->stream;
  pbVar7 = (byte *)(*pcVar2->vtbl->next)(pcVar2);
  bVar1 = *pbVar7;
  if (bVar1 < 0xf2) {
    return pbVar7;
  }
  do {
    if (bVar1 == 0xf2) {
      if ((g_compile_flags_c8 & 0x4000000) != 0) {
        return pbVar7;
      }
      reader->position = *(int *)(pbVar7 + 8);
      if ((g_compile_flags_c4 & 0x200000) != 0) {
        return pbVar7;
      }
      if (((g_compile_flags_c4 & 0x20000) != 0) && ((g_compile_flags_c4 & 0x20) == 0)) {
        il_emit_pragma_or_segment_record(0x24);
      }
    }
    else if (bVar1 == 0xf7) {
      pcVar3 = reader->top;
      if (pcVar3->kind != 1) {
        return pbVar7;
      }
      if (pcVar3 != (c1_token_source_frame *)0x0) {
        reader->top = pcVar3->prev;
        reader->position = pcVar3->position;
        if (pcVar3->on_pop != (_func_193 *)0x0) {
          (*pcVar3->on_pop)();
        }
      }
    }
    else if (bVar1 == 0xf3) {
      pcVar2 = *(c1xx_token_stream **)(pbVar7 + 8);
      (*pcVar2->vtbl->start)(pcVar2);
      token_source_push(reader,pcVar2,10,1,(void *)0x0,&g_token_position);
      pcVar2 = reader->top->stream;
      if ((pcVar2->flags & 2) == 0) {
        pcVar2->flags = pcVar2->flags | 2;
        (*pcVar2->vtbl->append)(pcVar2,g_token_end_of_stream);
      }
    }
    else if (g_token_class[bVar1] == 0xf6) {
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
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pbVar7 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          a = g_arenas + g_token_arena_index;
          pbVar7 = a->cur;
          pbVar4 = g_arenas[g_token_arena_index].end;
          a->cur = pbVar7 + 0x30;
          if (pbVar4 < pbVar7 + 0x30) {
            arena_grow(a);
          }
        }
        pfVar5 = g_last_name;
        if (pbVar7 != (byte *)0x0) {
          *pbVar7 = 6;
          *(fe_name **)(pbVar7 + 8) = pfVar5;
          *(int *)(pbVar7 + 0xc) = g_token_position;
          return pbVar7;
        }
        return (byte *)0x0;
      }
    }
    else {
      if ((g_compile_flags_c8 & 0x4000000) != 0) {
        return pbVar7;
      }
      if (bVar1 != 0xf4) {
        return pbVar7;
      }
      pbVar7 = (byte *)pragma_process_saved_tokens(pbVar7);
      if (pbVar7 != (byte *)0x0) {
        if (*pbVar7 != 2) {
          return pbVar7;
        }
        if (g_pch_directive_mode == 0) {
          return pbVar7;
        }
        bVar6 = pp_include_top_is_pseudo_file();
        if (!bVar6) {
          return pbVar7;
        }
        pp_include_pop_file();
        return pbVar7;
      }
    }
    pcVar2 = reader->top->stream;
    pbVar7 = (byte *)(*pcVar2->vtbl->next)(pcVar2);
    bVar1 = *pbVar7;
    if (bVar1 < 0xf2) {
      return pbVar7;
    }
  } while( true );
}

