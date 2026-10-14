char __cdecl eh_check_catch_type_count(c1_param_clause *clause)

{
  byte *pbVar1;
  char cVar2;
  bool bVar3;
  c1_catch_handler *pcVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  c1_symbol *pcVar7;
  c1_sym_link *pcVar8;
  c1_type *pcVar9;
  c1_arena *a;
  c1_type *pcVar10;
  c1_symbol *catch_param;
  
  if (clause->params == (c1_sym_list *)0x0) {
    pcVar8 = (c1_sym_link *)0x0;
  }
  else {
    pcVar8 = clause->params->head;
  }
  if ((clause->kind == 5) || (pcVar8 == (c1_sym_link *)0x0)) {
    catch_param = (c1_symbol *)0x0;
    pcVar10 = (c1_type *)0x0;
LAB_104ab8bb:
    diag_error(0x136);
  }
  else {
    pcVar10 = (pcVar8->type).type;
    catch_param = (c1_symbol *)&pcVar8[-1].position;
    if ((pcVar8 != (c1_sym_link *)0x0) && (pcVar8->next != (c1_sym_link *)0x0)) goto LAB_104ab8bb;
  }
  scope_pop_if_kind1(g_current_scope);
  pcVar4 = eh_add_catch_handler(catch_param);
  func_begin_compound_statement();
  if (pcVar4 == (c1_catch_handler *)0x0) {
    bVar3 = false;
  }
  else if (pcVar10 == (c1_type *)0x0) {
    bVar3 = false;
  }
  else if (catch_param->name == g_name_formal) {
    bVar3 = false;
  }
  else {
    (*g_current_scope->current->vtbl->insert)(catch_param);
    catch_param->kind = catch_param->kind & 0xea | 10;
    if ((catch_param->type->code & 0x8f) == 0x83) {
      pcVar9 = type_array_to_pointer(catch_param->type);
      catch_param->type = pcVar9;
      catch_param->flags5 = catch_param->flags5 & 0xfb;
    }
    bVar3 = true;
  }
  a = g_arenas + g_expr_arena_index;
  pcVar5 = (c1_node *)a->cur;
  pcVar6 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar5[1].op;
  if (pcVar6 < pcVar5 + 1) {
    arena_grow(a);
  }
  pcVar5->kind = '\0';
  pcVar5->op = 0xaa;
  pcVar5->left = pcVar4;
  il_emit_eh_catch(pcVar5);
  if (pcVar10 != (c1_type *)0x0) {
    cVar2 = (char)pcVar10->code;
    pcVar9 = pcVar10;
    while (cVar2 < '\0') {
      pcVar9 = pcVar9->base;
      cVar2 = (char)pcVar9->code;
    }
    if ((pcVar9->code & 0x300) != 0) {
      pcVar7 = (pcVar9->extra).cls;
      goto LAB_104ab95b;
    }
  }
  pcVar7 = (c1_symbol *)0x0;
LAB_104ab95b:
  pcVar5 = tree_new_int_constant(0);
  pcVar6 = tree_new_int_constant(0);
  pcVar5 = expr_build_eh_state_update(pcVar6,pcVar5,pcVar7);
  pbVar1 = (byte *)((int)pcVar5->left + 0x17);
  *pbVar1 = *pbVar1 | 1;
  stmt_emit_expression(pcVar5);
  pcVar7 = sym_new_kind1_placeholder(g_name_formal);
  pcVar7->type = pcVar10;
  pcVar7->storage = pcVar7->storage & 0xf8 ^ 4;
  eh_catch_handler_flow_state(pcVar7);
  if (bVar3) {
    eh_register_destructible_object(catch_param,1);
  }
  return '\x01';
}

