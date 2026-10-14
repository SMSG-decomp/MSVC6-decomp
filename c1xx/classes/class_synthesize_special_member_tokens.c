void __cdecl class_synthesize_special_member_tokens(c1_symbol *key,c1_symbol *sym)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  c1_u8 *pcVar3;
  int *piVar4;
  c1xx_token_stream *pcVar5;
  void *pvVar6;
  c1_u8 *pcVar7;
  c1xx_token_stream *pcVar8;
  int iVar9;
  c1_u8 *tok;
  c1_u8 *tok_2;
  c1_u8 *tok_3;
  c1_u8 *tok_4;
  c1_arena *a;
  int iVar10;
  uint arena;
  uint *puVar11;
  uint *puVar12;
  c1_vbase_vector *local_18;
  short iter_index;
  int *base_entry;
  c1_symbol *local_c;
  int base_offset;
  char local_4;
  
  if ((key->flags3 & 4) != 0) {
    return;
  }
  if (((key->kind & 0x1f) != 4) && ((*(byte *)((int)&key->tail + 8) & 8) != 0)) {
    return;
  }
  iVar10 = (int)(char)(sym->tail).fn.special_kind;
  if (iVar10 == 0) {
    return;
  }
  arena = (~g_compile_flags_c8 | 0xbfffffff) >> 0x1e;
  piVar4 = arena_alloc(g_arenas + arena,8);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    *piVar4 = g_token_arena_index;
    piVar4[1] = (int)g_token_arena_stack;
  }
  g_token_arena_index = arena;
  g_token_arena_stack = piVar4;
  if (g_token_stream_queues[arena].top == (c1_token_source_frame *)0x0) {
    pcVar5 = arena_alloc(g_arenas + arena,0x38);
    if (pcVar5 == (c1xx_token_stream *)0x0) {
      pcVar5 = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar5 = token_stream_init(pcVar5,arena,0);
    }
    token_source_push(g_token_stream_queues + arena,pcVar5,arena,0,(void *)0x0,&g_token_position);
  }
  pcVar5 = (g_token_stream_queues[arena].top)->stream;
  if (((iVar10 < 1) || (10 < iVar10)) && (iVar10 != 0x11)) {
    if ((10 < iVar10) && (iVar10 < 0x12)) {
      pcVar7 = arena_or_pool_alloc(0x30,arena);
      pcVar8 = g_vec_helper_prefix_tokens;
      if (pcVar7 == (c1_u8 *)0x0) {
        pcVar7 = (c1_u8 *)0x0;
      }
      else {
        *pcVar7 = 0xf3;
        *(c1xx_token_stream **)(pcVar7 + 8) = pcVar8;
      }
      (*pcVar5->vtbl->append)(pcVar5,(int)pcVar7);
      pcVar7 = arena_or_pool_alloc(0x30,arena);
      if (pcVar7 == (c1_u8 *)0x0) {
        pcVar7 = (c1_u8 *)0x0;
      }
      else {
        pvVar6 = class_special_member_name(iVar10);
        *pcVar7 = '\x06';
        *(void **)(pcVar7 + 8) = pvVar6;
        *(int *)(pcVar7 + 0xc) = g_token_position;
      }
      (*pcVar5->vtbl->append)(pcVar5,(int)pcVar7);
    }
  }
  else {
    token_stream_put_function_header(sym,pcVar5,arena);
  }
  if (((iVar10 < 1) || (10 < iVar10)) && (iVar10 != 0x11)) {
    if ((10 < iVar10) && (iVar10 < 0x12)) {
      g_yylval = (uint)g_vec_iterator_params_tokens;
      if (g_token_arena_index == 0) {
        pcVar7 = pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        pcVar7 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (pcVar7 == (c1_u8 *)0x0) {
        pcVar7 = (c1_u8 *)0x0;
      }
      else {
        *pcVar7 = 0xf3;
        puVar11 = &g_yylval;
        puVar12 = (uint *)(pcVar7 + 8);
        for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
      }
      (*pcVar5->vtbl->append)(pcVar5,(int)pcVar7);
      token_list_clear_saved_state((int *)&g_vec_iterator_params_tokens->first);
      (*pcVar5->vtbl->append)(pcVar5,g_token_rparen);
      (*pcVar5->vtbl->append)(pcVar5,(int)g_token_lbrace);
      if (iVar10 == 0xb) {
        g_yylval = (uint)g_vec_ctor_iterator_body_tokens;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar7 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pcVar7 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (pcVar7 == (c1_u8 *)0x0) {
          pcVar7 = (c1_u8 *)0x0;
        }
        else {
          *pcVar7 = 0xf3;
          puVar11 = &g_yylval;
          puVar12 = (uint *)(pcVar7 + 8);
          for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
        }
        (*pcVar5->vtbl->append)(pcVar5,(int)pcVar7);
        pcVar8 = g_vec_ctor_iterator_body_tokens;
      }
      else if (iVar10 == 0xc) {
        g_yylval = (uint)g_vec_ctor_vb_body_tokens;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar7 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pcVar7 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (pcVar7 == (c1_u8 *)0x0) {
          (*pcVar5->vtbl->append)(pcVar5,0);
          pcVar8 = g_vec_ctor_vb_body_tokens;
        }
        else {
          *pcVar7 = 0xf3;
          puVar11 = &g_yylval;
          puVar12 = (uint *)(pcVar7 + 8);
          for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          (*pcVar5->vtbl->append)(pcVar5,(int)pcVar7);
          pcVar8 = g_vec_ctor_vb_body_tokens;
        }
      }
      else {
        if (iVar10 != 0xd) goto LAB_1041f581;
        g_yylval = (uint)g_vec_dtor_body_tokens;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar7 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          a = g_arenas + g_token_arena_index;
          pcVar7 = a->cur;
          pcVar3 = g_arenas[g_token_arena_index].end;
          a->cur = pcVar7 + 0x30;
          if (pcVar3 < pcVar7 + 0x30) {
            arena_grow(a);
          }
        }
        if (pcVar7 == (c1_u8 *)0x0) {
          (*pcVar5->vtbl->append)(pcVar5,0);
          pcVar8 = g_vec_dtor_body_tokens;
        }
        else {
          *pcVar7 = 0xf3;
          puVar11 = &g_yylval;
          puVar12 = (uint *)(pcVar7 + 8);
          for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          (*pcVar5->vtbl->append)(pcVar5,(int)pcVar7);
          pcVar8 = g_vec_dtor_body_tokens;
        }
      }
      token_list_clear_saved_state((int *)&pcVar8->first);
    }
  }
  else {
    if (iVar10 == 2) {
      sym = (c1_symbol *)0x0;
      token_source_push((c1_token_reader *)&g_token_record_position,pcVar5,arena,0,(void *)0x0,
                        &g_token_position);
      local_4 = ((key->detail).cls)->vbases != (c1_vbase_vector *)0x0;
      if ((bool)local_4) {
        local_18 = ((key->detail).cls)->vbases;
        iter_index = 0;
        while ((local_4 != '\0' &&
               (iVar9 = vector_iterator_next((uint *)&local_18), (char)iVar9 != '\0'))) {
          local_c = (c1_symbol *)*base_entry;
          base_offset = base_entry[1];
          class_synth_append_base_init(local_c,(int *)&sym);
        }
      }
      class_for_each_member((int)key,class_synth_each_base_init,(int)&sym);
      class_for_each_member((int)key,class_synth_copy_ctor_member_init_tokens,(int)&sym);
      if (g_token_save_frame != (c1_token_source_frame *)0x0) {
        ppcVar1 = &g_token_save_frame->prev;
        g_token_record_position = g_token_save_frame->position;
        pp_Var2 = &g_token_save_frame->on_pop;
        g_token_save_frame = *ppcVar1;
        if (*pp_Var2 != (_func_193 *)0x0) {
          (**pp_Var2)();
        }
      }
    }
    (*pcVar5->vtbl->append)(pcVar5,(int)g_token_lbrace);
    if (iVar10 == 3) {
      if ((((key->detail).cls)->implicit_state41 & 8) == 0) {
        token_source_push((c1_token_reader *)&g_token_record_position,pcVar5,arena,0,(void *)0x0,
                          &g_token_position);
        if ((((key->detail).cls)->layout_flags3b & 0x10) != 0) {
          (*pcVar5->vtbl->append)(pcVar5,(int)g_token_if);
          (*pcVar5->vtbl->append)(pcVar5,g_token_lparen);
          g_yylval = (uint)g_name_most_derived;
          if (g_token_arena_index == 0) {
            tok_4 = pool_alloc_raw(&g_pool_default,0x30);
          }
          else {
            tok_4 = arena_alloc(g_arenas + g_token_arena_index,0x30);
          }
          if (tok_4 == (c1_u8 *)0x0) {
            tok_4 = (c1_u8 *)0x0;
          }
          else {
            *tok_4 = '\x06';
            puVar11 = &g_yylval;
            puVar12 = (uint *)(tok_4 + 8);
            for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
              *puVar12 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar12 = puVar12 + 1;
            }
          }
          (*pcVar5->vtbl->append)(pcVar5,(int)tok_4);
          (*pcVar5->vtbl->append)(pcVar5,g_token_rparen);
          (*pcVar5->vtbl->append)(pcVar5,(int)g_token_lbrace);
          local_4 = ((key->detail).cls)->vbases != (c1_vbase_vector *)0x0;
          if ((bool)local_4) {
            local_18 = ((key->detail).cls)->vbases;
            iter_index = 0;
            while ((local_4 != '\0' &&
                   (iVar10 = vector_iterator_next((uint *)&local_18), (char)iVar10 != '\0'))) {
              local_c = (c1_symbol *)*base_entry;
              base_offset = base_entry[1];
              class_synth_append_base_assign(local_c);
            }
          }
          (*pcVar5->vtbl->append)(pcVar5,(int)g_token_rbrace);
        }
        class_for_each_member((int)key,class_synth_each_base_assign,0);
        class_for_each_member((int)key,class_synth_assign_member_tokens,0);
        if (g_token_save_frame != (c1_token_source_frame *)0x0) {
          ppcVar1 = &g_token_save_frame->prev;
          g_token_record_position = g_token_save_frame->position;
          pp_Var2 = &g_token_save_frame->on_pop;
          g_token_save_frame = *ppcVar1;
          if (*pp_Var2 != (_func_193 *)0x0) {
            (**pp_Var2)();
          }
        }
      }
      else {
        (*pcVar5->vtbl->append)(pcVar5,(int)g_token_star);
        g_yylval = g_name_this;
        if (g_token_arena_index == 0) {
          tok = pool_alloc_raw(&g_pool_default,0x30);
        }
        else {
          tok = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (tok == (c1_u8 *)0x0) {
          tok = (c1_u8 *)0x0;
        }
        else {
          *tok = 0x90;
          puVar11 = &g_yylval;
          puVar12 = (uint *)(tok + 8);
          for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
        }
        (*pcVar5->vtbl->append)(pcVar5,(int)tok);
        (*pcVar5->vtbl->append)(pcVar5,(int)g_token_assign);
        g_yylval = (uint)PTR_104d164c;
        if (g_token_arena_index == 0) {
          tok_2 = pool_alloc_raw(&g_pool_default,0x30);
        }
        else {
          tok_2 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (tok_2 == (c1_u8 *)0x0) {
          tok_2 = (c1_u8 *)0x0;
        }
        else {
          *tok_2 = '\x06';
          puVar11 = &g_yylval;
          puVar12 = (uint *)(tok_2 + 8);
          for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
        }
        (*pcVar5->vtbl->append)(pcVar5,(int)tok_2);
        (*pcVar5->vtbl->append)(pcVar5,(int)g_token_semicolon);
      }
      (*pcVar5->vtbl->append)(pcVar5,(int)g_token_return);
      (*pcVar5->vtbl->append)(pcVar5,(int)g_token_star);
      g_yylval = g_name_this;
      if (g_token_arena_index == 0) {
        tok_3 = pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        tok_3 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (tok_3 == (c1_u8 *)0x0) {
        tok_3 = (c1_u8 *)0x0;
      }
      else {
        *tok_3 = 0x90;
        puVar11 = &g_yylval;
        puVar12 = (uint *)(tok_3 + 8);
        for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
      }
      (*pcVar5->vtbl->append)(pcVar5,(int)tok_3);
      (*pcVar5->vtbl->append)(pcVar5,(int)g_token_semicolon);
    }
    (*pcVar5->vtbl->append)(pcVar5,(int)g_token_rbrace);
  }
LAB_1041f581:
  if ((g_compile_flags_c8 & 0x40000000) != 0) {
    (*pcVar5->vtbl->append)(pcVar5,(int)g_token_end_parse);
  }
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  return;
}

