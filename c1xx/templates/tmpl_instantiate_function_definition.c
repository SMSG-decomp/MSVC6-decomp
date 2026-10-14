void __fastcall tmpl_instantiate_function_definition(c1xx_tmpl_function_item *item)

{
  c1_symbol *pcVar1;
  void *pvVar2;
  bool bVar3;
  c1_symbol *pcVar4;
  c1_arg_list *pcVar5;
  c1_sym_list *params;
  void *pvVar6;
  c1xx_token_stream *pcVar7;
  int *piVar8;
  c1_sym_list *pcVar9;
  c1xx_block_scope *pcVar10;
  void **inst_record;
  void *pvVar11;
  c1_u8 *new_token;
  void *pvVar12;
  c1_u8 *new_token_2;
  c1xx_block_scope *pcVar13;
  c1_u8 *new_token_3;
  int iVar14;
  byte bVar15;
  uint *puVar16;
  c1_u8 *new_token_4;
  uint *puVar17;
  c1xx_token_stream *stream;
  c1_symbol *local_10;
  
  pcVar1 = item->sym;
  bVar15 = pcVar1->kind & 0x1f;
  if ((bVar15 != 7) && (bVar15 != 8)) {
    diag_fatal(1,".\\template.cpp",0x2b7);
  }
  if ((((*(byte *)((int)&pcVar1->tail + 9) & 0x40) != 0) && ((pcVar1->flags2 & 4) == 0)) &&
     ((((pcVar1->key_ref & 3) != 0 && ((pcVar1->flags22 & 0x20) == 0)) ||
      ((pcVar1->flags22 & 0x10) != 0)))) {
    bVar3 = false;
    pcVar1 = item->sym;
    local_10 = (c1_symbol *)0x0;
    if (item->parameter_scope == (void *)0x0) {
      bVar3 = true;
      pcVar4 = tmpl_template_of_instance(pcVar1);
      item->tmpl = pcVar4;
      pcVar5 = symtab_15f4_lookup(pcVar1);
      item->args = pcVar5;
      if ((pcVar1->scope_index != 0) &&
         ((g_scope_vector->entries[(short)pcVar1->scope_index]->kind & 0x1f) == 0x19)) {
        local_10 = g_scope_vector->entries[(short)pcVar1->scope_index];
      }
    }
    else {
      symtab_1604_insert(pcVar1,item->tmpl);
    }
    if (((pcVar1->kind & 0x1f) == 7) && (pcVar1->scope_index != 0)) {
      local_10 = g_scope_vector->entries[(short)pcVar1->scope_index];
    }
    params = tmpl_lookup_parameter_list(item->tmpl);
    pvVar6 = symtab_1600_lookup(item->tmpl);
    if (pvVar6 != (void *)0x0) {
      pcVar1->storage = pcVar1->storage | 0x40;
      pcVar1->flags21 = pcVar1->flags21 | 1;
      if (g_token_stream_queues[2].top == (c1_token_source_frame *)0x0) {
        pcVar7 = arena_alloc(g_arenas + 2,0x38);
        if (pcVar7 == (c1xx_token_stream *)0x0) {
          pcVar7 = (c1xx_token_stream *)0x0;
        }
        else {
          pcVar7 = token_stream_init(pcVar7,2,0);
        }
        token_source_push(g_token_stream_queues + 2,pcVar7,2,0,(void *)0x0,&g_token_position);
      }
      pcVar7 = (g_token_stream_queues[2].top)->stream;
      piVar8 = arena_alloc(g_arenas + 2,8);
      if (piVar8 == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        *piVar8 = g_token_arena_index;
        piVar8[1] = (int)g_token_arena_stack;
      }
      g_token_arena_index = 2;
      g_token_arena_stack = piVar8;
      pcVar9 = symtab_1608_lookup(pcVar1);
      if (pcVar9 == (c1_sym_list *)0x0) {
        pcVar10 = tmpl_bind_arguments(params,item->args,pcVar1,'\0','\0',0);
      }
      else {
        pcVar13 = arena_alloc(g_arenas + 2,0x18);
        pcVar10 = (c1xx_block_scope *)0x0;
        if (pcVar13 != (c1xx_block_scope *)0x0) {
          pcVar13->outer = (c1xx_scope *)0x0;
          pcVar13->kind = 0xfa;
          pcVar13->parent = (c1xx_scope *)0x0;
          pcVar13->usings = (c1_using_directive *)0x0;
          pcVar13->symbols = pcVar9;
          pcVar13->vtbl = (c1xx_block_scope_vtbl *)&PTR_block_scope_has_entries_104bcac0;
          pcVar10 = pcVar13;
        }
      }
      inst_record = arena_alloc(g_arenas + 2,0x24);
      if (inst_record == (void **)0x0) {
        g_yylval = 0;
      }
      else {
        pvVar11 = symtab_160c_lookup(item->tmpl);
        pvVar12 = (void *)item->position;
        pvVar2 = item->parameter_scope;
        inst_record[1] = (void *)item->function_word;
        *inst_record = pvVar2;
        inst_record[2] = (void *)0x0;
        inst_record[3] = (void *)0x0;
        inst_record[4] = pcVar1;
        inst_record[5] = pcVar10;
        inst_record[6] = local_10;
        inst_record[7] = pvVar12;
        inst_record[8] = pvVar11;
        g_yylval = (uint)inst_record;
      }
      if (g_token_arena_index == 0) {
        new_token = pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        new_token = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (new_token == (c1_u8 *)0x0) {
        new_token = (c1_u8 *)0x0;
      }
      else {
        *new_token = 0xca;
        puVar16 = &g_yylval;
        puVar17 = (uint *)(new_token + 8);
        for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar17 = *puVar16;
          puVar16 = puVar16 + 1;
          puVar17 = puVar17 + 1;
        }
      }
      stream = pcVar7;
      (*pcVar7->vtbl->append)(pcVar7,(int)new_token);
      new_token_4 = g_arenas[2].cur;
      if (bVar3) {
        pvVar12 = tmpl_definition_table_lookup(item->tmpl);
        g_yylval = (uint)pvVar12;
        if (g_token_arena_index == 0) {
          new_token_2 = pool_alloc_raw(&g_pool_default,0x30);
        }
        else {
          new_token_2 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (new_token_2 == (c1_u8 *)0x0) {
          new_token_2 = (c1_u8 *)0x0;
        }
        else {
          *new_token_2 = 0xf3;
          puVar16 = &g_yylval;
          puVar17 = (uint *)(new_token_2 + 8);
          for (iVar14 = 10; pcVar7 = stream, iVar14 != 0; iVar14 = iVar14 + -1) {
            *puVar17 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar17 = puVar17 + 1;
          }
        }
        (*pcVar7->vtbl->append)(pcVar7,(int)new_token_2);
        token_list_clear_saved_state((int *)((int)pvVar12 + 0xc));
        g_yylval = (uint)pvVar6;
      }
      else {
        g_arenas[2].cur = g_arenas[2].cur + 0x30;
        if (g_arenas[2].end < g_arenas[2].cur) {
          arena_grow(g_arenas + 2);
        }
        if (new_token_4 == (c1_u8 *)0x0) {
          new_token_4 = (c1_u8 *)0x0;
        }
        else {
          *new_token_4 = 0xc9;
          *(c1_symbol **)(new_token_4 + 8) = pcVar1;
        }
        (*pcVar7->vtbl->append)(pcVar7,(int)new_token_4);
        g_yylval = (uint)pvVar6;
      }
      pvVar6 = (void *)g_yylval;
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        new_token_3 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        new_token_3 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (new_token_3 == (c1_u8 *)0x0) {
        new_token_3 = (c1_u8 *)0x0;
        stream = pcVar7;
      }
      else {
        *new_token_3 = 0xf3;
        puVar16 = &g_yylval;
        puVar17 = (uint *)(new_token_3 + 8);
        for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar17 = *puVar16;
          puVar16 = puVar16 + 1;
          puVar17 = puVar17 + 1;
        }
      }
      (*stream->vtbl->append)(stream,(int)new_token_3);
      token_list_clear_saved_state((int *)((int)pvVar6 + 0xc));
      (*stream->vtbl->append)(stream,(int)g_token_end_parse);
      g_token_arena_index = *g_token_arena_stack;
      g_token_arena_stack = (int *)g_token_arena_stack[1];
    }
    return;
  }
  return;
}

