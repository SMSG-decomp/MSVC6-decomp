c1_u8 * __fastcall parse_check_missing_token(int *head,undefined4 param_2,char *token)

{
  byte *pbVar1;
  byte bVar2;
  c1_u8 cVar3;
  c1_u8 *pcVar4;
  c1xx_emitter_suspend *pcVar5;
  c1_symbol *pcVar6;
  c1_arena *a;
  c1_u8 *pcVar7;
  c1_lookup_entry *pcVar8;
  uint class_flags;
  char *pcVar9;
  undefined2 extraout_var;
  int iVar10;
  undefined4 extraout_ECX;
  undefined2 uVar11;
  c1_u16 cVar12;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 edx;
  undefined4 extraout_EDX_01;
  uint *puVar13;
  int *piVar14;
  uint *puVar15;
  int *piVar16;
  uint in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  uint uVar17;
  uint uuid;
  uint spec_10;
  
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,token);
  if ((g_compile_flags_c8 & 0x2000000) != 0) {
    pcVar7 = tmpl_record_class_body_tokens();
    pcVar9 = lex_peek_token((uint *)&g_token_position);
    edx = extraout_EDX;
    if (*pcVar9 != '\x7f') {
      diag_error(0x8f);
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,g_token_semicolon);
      edx = extraout_EDX_01;
    }
    pcVar5 = g_emitter_suspend;
    if (g_emitter_suspend->depth == 0) {
      g_emitter_suspend->saved = g_il_emitter;
      g_il_emitter = il_emitter_get_default();
      pcVar5->enabled = '\0';
      edx = extraout_EDX_00;
    }
    pcVar5->depth = pcVar5->depth + 1;
    pcVar7 = class_parse_head(head,pcVar7,edx);
    pcVar5 = g_emitter_suspend;
    iVar10 = g_emitter_suspend->depth + -1;
    g_emitter_suspend->depth = iVar10;
    if (iVar10 == 0) {
      g_il_emitter = pcVar5->saved;
      pcVar5->enabled = '\x01';
    }
    iVar10 = head[1];
    if (iVar10 == 0) {
      return pcVar7;
    }
    if (g_current_scope->current != g_current_scope->global_scope) {
      cVar3 = g_current_scope->current->kind;
      if ((cVar3 != '\0') && (cVar3 != 0xff)) {
        return pcVar7;
      }
      if (*(short *)(iVar10 + 6) == 0) {
        if (g_class_depth < 0) {
          pcVar6 = scope_current_namespace(g_current_scope);
          iVar10 = head[1];
          cVar12 = *(c1_u16 *)&pcVar6->type->base;
        }
        else {
          *(byte *)(iVar10 + 2) =
               (g_class_def_stack[g_class_depth].flags ^ *(byte *)(iVar10 + 2)) & 3 ^
               *(byte *)(iVar10 + 2);
          iVar10 = head[1];
          cVar12 = (((g_class_def_stack[g_class_depth].cls)->detail).cls)->scope_index;
        }
        *(c1_u16 *)(iVar10 + 6) = cVar12;
      }
    }
    *(int *)(head[1] + 0x10) = g_token_position;
    return pcVar7;
  }
  uVar11 = extraout_var;
  if (((g_compile_flags_cc & 0x100000) != 0) && (g_class_depth < 0)) {
    pcVar8 = lookup_name_in_context(g_current_scope,(void *)*head,0x20);
    if (pcVar8 == (c1_lookup_entry *)0x0) {
      pcVar6 = (c1_symbol *)0x0;
    }
    else {
      pcVar6 = pcVar8->sym;
    }
    head[1] = (int)pcVar6;
    uVar17 = CONCAT31((int3)((uint)extraout_ECX >> 8),pcVar6->kind) & 0xffffff1f;
    if ((char)uVar17 == '\x12') {
      uVar17 = *(uint *)(*(int *)pcVar6->type + 8);
      head[1] = uVar17;
    }
    uVar11 = (undefined2)(uVar17 >> 0x10);
    pbVar1 = (byte *)(*(int *)(head[1] + 0x24) + 0x3e);
    *pbVar1 = *pbVar1 | 0x40;
  }
  if ((c1_symbol *)head[1] == (c1_symbol *)0x0) {
    uVar17 = 0x10433de5;
    pcVar6 = decl_tag_definition_lookup(*head,CONCAT22(uVar11,(short)head[3]),(void **)(head + 0xb))
    ;
    head[1] = (int)pcVar6;
    if ((pcVar6 == (c1_symbol *)0x0) && ((*(uint *)(*head + 8) & 0x2000000) != 0)) {
      return g_token_newline;
    }
  }
  else {
    pcVar9 = diag_symbol_display_name((c1_symbol *)head[1]);
    uVar17 = 0x10458b64;
    pcVar6 = esu_check_tag_and_begin_enum
                       ((c1_symbol *)head[1],CONCAT22((short)((uint)pcVar9 >> 0x10),(short)head[3]))
    ;
    head[1] = (int)pcVar6;
  }
  if (head[1] == 0) {
    type_keyword_text(*(ushort *)(head + 3));
    diag_error(0x289);
    return g_token_newline;
  }
  if ((*(byte *)(head[1] + 3) & 4) == 0) {
    g_yylval_spec_insert_fn = (void *)head[0xb];
    *(int *)(head[1] + 0x10) = g_token_position;
    uuid = 0x10433e2d;
    class_check_uuid_redefinition((c1_symbol *)head[1],(c1_u8 *)(head + 4));
    if ((*(ushort *)(head + 3) & 0x300) != 0) {
      pbVar1 = (byte *)(*(int *)(head[1] + 0x24) + 0x3e);
      *pbVar1 = *pbVar1 | 4;
    }
    if ((*(byte *)((int)head + 0xd) & 1) == 0) {
      if ((*(byte *)((int)head + 0x12) & 0xc) != 0) {
        bVar2 = *(byte *)(head[1] + 0x22);
        *(byte *)(head[1] + 0x22) = (bVar2 ^ *(byte *)((int)head + 0x12)) & 4 ^ bVar2;
        bVar2 = *(byte *)(head[1] + 0x22);
        *(byte *)(head[1] + 0x22) = (bVar2 ^ *(byte *)((int)head + 0x12)) & 8 ^ bVar2;
      }
      if ((*(byte *)(head + 9) & 2) != 0) {
        pbVar1 = (byte *)(*(int *)(head[1] + 0x24) + 0x3c);
        *pbVar1 = *pbVar1 | 0x80;
      }
      if (((((*(byte *)((int)head + 0x11) & 7) != 0) || ((*(byte *)((int)head + 0x12) & 3) != 0)) ||
          ((*(byte *)((int)head + 0x13) & 1) != 0)) ||
         (((*(byte *)((int)head + 0x13) & 0x9c) != 0 || ((*(byte *)((int)head + 0x12) & 0x40) != 0))
         )) {
        class_flags = format_buffer_acquire();
        spec_10 = 0x10458be5;
        format_buffer_free(class_flags);
        piVar14 = head + 4;
        piVar16 = (int *)&stack0xffffffdc;
        for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
          *piVar16 = *piVar14;
          piVar14 = piVar14 + 1;
          piVar16 = piVar16 + 1;
        }
        iVar10 = format_decl_specifiers_text
                           (0,in_stack_ffffffdc,in_stack_ffffffe0,uVar17,uuid,spec_10,class_flags);
        pcVar9 = format_buffer_text(iVar10);
        diag_warning(1,0x26,pcVar9);
        format_buffer_leave();
      }
      bVar2 = *(byte *)(*(int *)(head[1] + 0x24) + 0x3e);
      if ((bVar2 & 1) != 0) {
        *(byte *)(*(int *)(head[1] + 0x24) + 0x3e) = bVar2 | 4;
      }
      g_yylval_spec_type_sym = (c1_symbol *)head[1];
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
        pcVar4 = g_arenas[g_token_arena_index].end;
        a->cur = pcVar7 + 0x30;
        if (pcVar4 < pcVar7 + 0x30) {
          arena_grow(a);
        }
      }
      if (pcVar7 != (c1_u8 *)0x0) {
        *pcVar7 = '\"';
        puVar13 = &g_yylval;
        puVar15 = (uint *)(pcVar7 + 8);
        for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar15 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar15 = puVar15 + 1;
        }
        return pcVar7;
      }
    }
    else {
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      g_yylval_spec_type_sym = (c1_symbol *)head[1];
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
      if (pcVar7 != (c1_u8 *)0x0) {
        *pcVar7 = '#';
        puVar13 = &g_yylval;
        puVar15 = (uint *)(pcVar7 + 8);
        for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar15 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar15 = puVar15 + 1;
        }
        return pcVar7;
      }
    }
    return (c1_u8 *)0x0;
  }
  return g_token_newline;
}

