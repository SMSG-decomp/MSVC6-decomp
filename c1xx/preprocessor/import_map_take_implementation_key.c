void * __thiscall import_map_take_implementation_key(c1_import_key_list *list,uint key,char no_open)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  uint uVar3;
  c1xx_token_stream *pcVar4;
  c1_u8 *pcVar5;
  c1_import_key_node *pcVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  
  pcVar6 = list->head;
  if (pcVar6 == (c1_import_key_node *)0x0) {
    if (no_open == '\0') {
      uVar3 = pp_include_pop_file();
      pcVar4 = arena_alloc(g_arenas + 4,0x38);
      if (pcVar4 == (c1xx_token_stream *)0x0) {
        pcVar4 = (c1xx_token_stream *)0x0;
      }
      else {
        pcVar4 = token_stream_init(pcVar4,4,0);
      }
      token_source_push((c1_token_reader *)&g_token_record_position,pcVar4,4,0,(void *)0x0,
                        &g_token_position);
      g_yylval_word1 = (int)uVar3 >> 0x1f;
      g_yylval = uVar3;
      pcVar5 = arena_or_pool_alloc(0x30,g_token_arena_index);
      if (pcVar5 == (c1_u8 *)0x0) {
        pcVar5 = (c1_u8 *)0x0;
      }
      else {
        *pcVar5 = '<';
        puVar8 = &g_yylval;
        puVar9 = (uint *)(pcVar5 + 8);
        for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
      }
      (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)pcVar5);
      pcVar5 = token_new_position_marker(4);
      (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)pcVar5);
      (*g_token_save_frame->stream->vtbl->append)
                (g_token_save_frame->stream,(int)g_token_directive_end);
      (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,g_token_end_of_stream);
      pcVar4 = (c1xx_token_stream *)0x0;
      if (g_token_save_frame != (c1_token_source_frame *)0x0) {
        ppcVar1 = &g_token_save_frame->prev;
        pcVar4 = g_token_save_frame->stream;
        g_token_record_position = g_token_save_frame->position;
        pp_Var2 = &g_token_save_frame->on_pop;
        g_token_save_frame = *ppcVar1;
        if (*pp_Var2 != (_func_193 *)0x0) {
          (**pp_Var2)();
        }
      }
      g_yylval = (uint)pcVar4;
      pcVar5 = arena_or_pool_alloc(0x30,g_token_arena_index);
      if (pcVar5 != (c1_u8 *)0x0) {
        *pcVar5 = 0xf4;
        puVar8 = &g_yylval;
        puVar9 = (uint *)(pcVar5 + 8);
        for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        return pcVar5;
      }
      return (void *)0x0;
    }
  }
  else {
    do {
      if (key == pcVar6->key) {
        if (pcVar6->prev == (c1_import_key_node *)0x0) {
          list->head = pcVar6->next;
        }
        else {
          pcVar6->prev->next = pcVar6->next;
        }
        if (pcVar6->next != (c1_import_key_node *)0x0) {
          pcVar6->next->prev = pcVar6->prev;
          return g_token_newline;
        }
        list->tail = pcVar6->prev;
        return g_token_newline;
      }
    } while ((pcVar6->key <= key) && (pcVar6 = pcVar6->next, pcVar6 != (c1_import_key_node *)0x0));
  }
  return (void *)0x0;
}

