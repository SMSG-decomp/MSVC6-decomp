int __cdecl lex_end_of_input(void)

{
  _func_193 **pp_Var1;
  c1_token_source_frame *pcVar2;
  c1xx_il_emitter *saved_il_emitter;
  int saved_opt_Binl;
  char cVar3;
  c1xx_token_stream *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint *callback;
  uint *stream_next;
  uint *callback_2;
  uint *stream_next_2;
  uint *callback_3;
  uint *stream_next_3;
  uint *callback_4;
  uint *stream_next_4;
  
  iVar7 = g_token_position;
  saved_il_emitter = g_il_emitter;
  pcVar2 = g_token_stream_queues[3].top;
  if (g_error_count != 0) {
    while (pcVar2 != (c1_token_source_frame *)0x0) {
      g_token_stream_queues[3].top = pcVar2->prev;
      g_token_stream_queues[3].position = pcVar2->position;
      callback_4 = (uint *)&pcVar2->on_pop;
      pcVar2 = g_token_stream_queues[3].top;
      if ((code *)*callback_4 != (code *)0x0) {
        (*(code *)*callback_4)();
        pcVar2 = g_token_stream_queues[3].top;
      }
    }
    g_token_stream_queues[3].top = (c1_token_source_frame *)0x0;
    if (g_token_stream_queues[2].top == (c1_token_source_frame *)0x0) {
      g_token_stream_queues[3].top = (c1_token_source_frame *)0x0;
      return 0;
    }
    do {
      stream_next_4 = (uint *)&(g_token_stream_queues[2].top)->prev;
      g_token_stream_queues[2].position = (g_token_stream_queues[2].top)->position;
      pp_Var1 = &(g_token_stream_queues[2].top)->on_pop;
      g_token_stream_queues[2].top = (c1_token_source_frame *)*stream_next_4;
      if (*pp_Var1 != (_func_193 *)0x0) {
        (**pp_Var1)();
      }
    } while (g_token_stream_queues[2].top != (c1_token_source_frame *)0x0);
    return 0;
  }
  if (g_token_stream_queues[3].top == (c1_token_source_frame *)0x0) {
    if (g_token_stream_queues[2].top != (c1_token_source_frame *)0x0) {
      (*(g_token_stream_queues[2].top)->stream->vtbl->append)
                ((g_token_stream_queues[2].top)->stream,g_token_end_of_stream);
      pcVar4 = (c1xx_token_stream *)0x0;
      if (g_token_stream_queues[2].top != (c1_token_source_frame *)0x0) {
        stream_next_2 = (uint *)&(g_token_stream_queues[2].top)->prev;
        pcVar4 = (g_token_stream_queues[2].top)->stream;
        g_token_stream_queues[2].position = (g_token_stream_queues[2].top)->position;
        callback_2 = (uint *)&(g_token_stream_queues[2].top)->on_pop;
        g_token_stream_queues[2].top = (c1_token_source_frame *)*stream_next_2;
        if ((code *)*callback_2 != (code *)0x0) {
          (*(code *)*callback_2)();
        }
      }
      token_source_push((c1_token_reader *)&g_token_position,pcVar4,2,1,lex_fetch_pending_input,
                        &g_token_position);
      g_instantiation_feed_count = g_instantiation_feed_count + 1;
      return g_instantiation_feed_count;
    }
    if (g_token_stream_queues[0].top == (c1_token_source_frame *)0x0) {
      g_il_emitter = il_emitter_get_default();
      saved_opt_Binl = g_opt_Binl;
      uVar5 = g_compile_flags_c8 | 0x80;
      uVar9 = g_compile_flags_c8 >> 7;
      g_opt_Binl = 1;
      g_compile_flags_c8 = uVar5;
      if ((((g_dynamic_initializer_functions != (c1_vector *)0x0) &&
           (g_dynamic_initializer_functions->count != 0)) ||
          ((PTR_104d143c != (c1_vector *)0x0 && (PTR_104d143c->count != 0)))) ||
         (g_pending_destructor_helpers != 0)) {
        tu_emit_dynamic_initializers();
        if (g_dynamic_initializer_functions != (c1_vector *)0x0) {
          g_dynamic_initializer_functions->count = 0;
          uVar5 = g_dynamic_initializer_functions->capacity - 1;
          if (-1 < (int)uVar5) {
            do {
              uVar6 = uVar5 - 1;
              g_dynamic_initializer_functions->data[uVar5] = (void *)0x0;
              uVar5 = uVar6;
            } while (uVar6 < 0x80000000);
          }
        }
        if (PTR_104d143c != (c1_vector *)0x0) {
          iVar7 = lex_end_of_input_clear_vector
                            (PTR_104d143c,saved_il_emitter,saved_opt_Binl,(byte)uVar9 & 1,iVar7);
          return iVar7;
        }
      }
      g_pending_destructor_helpers = 0;
      cVar3 = tu_has_pending_special_members();
      if (cVar3 == '\0') {
        cVar3 = tmpl_queue_used_member_bodies();
        if (cVar3 == '\0') {
          if ((uVar9 & 1) != 0) {
            g_il_emitter = saved_il_emitter;
            g_token_position = iVar7;
            g_opt_Binl = saved_opt_Binl;
            return 0;
          }
          g_il_emitter = saved_il_emitter;
          g_compile_flags_c8 = g_compile_flags_c8 & 0xffffff7f;
          g_token_position = iVar7;
          g_opt_Binl = saved_opt_Binl;
          return 0;
        }
      }
      else {
        class_build_vector_helper_tokens();
        class_define_pending_special_members();
      }
      iVar8 = lex_end_of_input();
      g_il_emitter = saved_il_emitter;
      g_opt_Binl = saved_opt_Binl;
      if ((uVar9 & 1) == 0) {
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffff7f;
      }
      g_token_position = iVar7;
      return iVar8;
    }
    (*(g_token_stream_queues[0].top)->stream->vtbl->append)
              ((g_token_stream_queues[0].top)->stream,g_token_end_of_stream);
    pcVar4 = (c1xx_token_stream *)0x0;
    if (g_token_stream_queues[0].top != (c1_token_source_frame *)0x0) {
      stream_next_3 = (uint *)&(g_token_stream_queues[0].top)->prev;
      pcVar4 = (g_token_stream_queues[0].top)->stream;
      g_token_stream_queues[0].position = (g_token_stream_queues[0].top)->position;
      callback_3 = (uint *)&(g_token_stream_queues[0].top)->on_pop;
      g_token_stream_queues[0].top = (c1_token_source_frame *)*stream_next_3;
      if ((code *)*callback_3 != (code *)0x0) {
        (*(code *)*callback_3)();
      }
    }
    iVar7 = 0;
  }
  else {
    (*(g_token_stream_queues[3].top)->stream->vtbl->append)
              ((g_token_stream_queues[3].top)->stream,g_token_end_of_stream);
    if (g_token_stream_queues[3].top == (c1_token_source_frame *)0x0) {
      iVar7 = 3;
      pcVar4 = (c1xx_token_stream *)0x0;
    }
    else {
      stream_next = (uint *)&(g_token_stream_queues[3].top)->prev;
      pcVar4 = (g_token_stream_queues[3].top)->stream;
      g_token_stream_queues[3].position = (g_token_stream_queues[3].top)->position;
      callback = (uint *)&(g_token_stream_queues[3].top)->on_pop;
      g_token_stream_queues[3].top = (c1_token_source_frame *)*stream_next;
      if ((code *)*callback != (code *)0x0) {
        (*(code *)*callback)();
      }
      iVar7 = 3;
    }
  }
  token_source_push((c1_token_reader *)&g_token_position,pcVar4,iVar7,1,lex_fetch_pending_input,
                    &g_token_position);
  return 1;
}

