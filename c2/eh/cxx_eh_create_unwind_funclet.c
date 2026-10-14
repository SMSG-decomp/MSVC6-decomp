void __fastcall cxx_eh_create_unwind_funclet(c2_tuple *t)

{
  int32_t *piVar1;
  char cVar2;
  c2_scope_table *pcVar3;
  c2_cfg *pcVar4;
  int iVar5;
  c2_tuple *pcVar6;
  c2_tuple *funclet_label;
  c2_tuple *pcVar7;
  c2_fe_symbol *pcVar8;
  c2_function *funclet_fn;
  c2_tuple *pcVar9;
  c2_tuple *first;
  c2_eh_state *object;
  c2_operand *pcVar10;
  c2_const_operand *pcVar11;
  char *funclet_name;
  uint32_t op_flags;
  uint kind;
  char *pcVar12;
  code *insert_fn_00;
  c2_tuple *dtor_body;
  uint32_t guarded;
  c2_eh_state *local_4;
  c2_insert_fn *insert_fn;
  c2_eh_op *eh_op;
  
  eh_op = (c2_eh_op *)(t->u20).eh_construct;
  dtor_body = (eh_op->construct).dtor_body;
  (eh_op->construct).dtor_body = (c2_tuple *)0x0;
  if (dtor_body != (c2_tuple *)0x0) {
    tuple_range_clear_line(dtor_body,(c2_tuple *)0x0);
  }
  object = g_eh_return_object_record;
  op_flags = (eh_op->construct).flags;
  kind = op_flags & 7;
  if (((kind == 4) && ((op_flags & 0x10) == 0)) || ((op_flags & 0x40) != 0)) {
    guarded = 1;
  }
  else {
    guarded = 0;
  }
  if ((op_flags & 0x100) != 0) {
    object = cxx_eh_new_object_record(7,0,0);
    push_eh_state(object);
    tuple_unlink_free(t);
    return;
  }
  if ((op_flags & 0x10) != 0) {
    if ((kind != 2) && (kind != 4)) {
      object = cxx_eh_new_object_record(kind,guarded,1);
      (object->u1c).unwind_body = dtor_body;
      push_eh_state(object);
      if (guarded != 0) {
        pcVar10 = operand_new_sym(0x14a,0x1004,object->guard_word);
        insert_fn_00 = tuple_insert_before;
        pcVar6 = t;
        pcVar11 = operand_new_intconst(0x1004,object->guard_bit,0);
        tuple_new_binary(0x173,0x1004,pcVar10,pcVar10,pcVar11,insert_fn_00,pcVar6);
      }
      lower_copy_pseudo(t);
      return;
    }
    node_list_free((c2_node *)dtor_body);
    lower_copy_pseudo(t);
    return;
  }
  if (kind == 4) {
    if (g_eh_return_object_record != (c2_eh_state *)0x0) {
      funclet_fn = g_eh_return_object_record->funclet;
      (eh_op->construct).dtor_body = (c2_tuple *)0x0;
      piVar1 = &funclet_fn->funclet_refs;
      *piVar1 = *piVar1 + 1;
      goto LAB_107546e9;
    }
  }
  else {
    local_4 = cxx_eh_new_object_record(kind,guarded,0);
    if (kind != 2) {
      push_eh_state(local_4);
      (local_4->u1c).unwind_body = dtor_body;
    }
  }
  object = local_4;
  pcVar6 = clone_tuple_list(dtor_body);
  funclet_label = (c2_tuple *)list_last((c2_link *)pcVar6);
  pcVar7 = tuple_new_pseudo(0x1a7,0x1004);
  tuple_splice_after(funclet_label,pcVar7);
  pcVar8 = label_symbol_new();
  funclet_label = tuple_new_label(pcVar8);
  pcVar10 = funclet_label->src;
  *(undefined1 *)&pcVar10[1].next = 0x54;
  *(uint *)((int)&pcVar10[1].rank + 2) = *(uint *)((int)&pcVar10[1].rank + 2) | 1;
  tuple_splice_after(funclet_label,pcVar6);
  if (g_opt_edit_and_continue != 0) {
    op_flags = 0xffffffff;
    pcVar12 = g_cur_function->fsym->name;
    do {
      if (op_flags == 0) break;
      op_flags = op_flags - 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    funclet_name = arena_alloc(0,~op_flags + 0x1c);
    iVar5 = g_eh_name_counter;
    g_eh_name_counter = g_eh_name_counter + 1;
    sprintf(funclet_name,"__unwindfunclet$%s$%d",g_cur_function->fsym->name,iVar5);
    (funclet_label->src->u18).reg = (c2_symbol *)funclet_name;
  }
  funclet_fn = arena_alloc(1,0x40);
  pcVar3 = g_cur_function->scope;
  funclet_fn->fsym = g_cur_function->fsym;
  funclet_fn->scope = pcVar3;
  funclet_fn->flags = funclet_fn->flags | 0x1000;
  pcVar9 = tuple_new_block_boundary();
  first = tuple_new_block_boundary();
  tuple_splice_after(pcVar9,first);
  cfg_create(funclet_fn,pcVar9,first,1);
  tuple_splice_after(pcVar9,funclet_label);
  if (guarded != 0) {
    g_cur_line = 0;
    if (kind == 4) {
      object = cxx_eh_new_object_record(4,1,0);
      g_eh_return_object_record = object;
    }
    pcVar8 = label_symbol_new();
    pcVar9 = tuple_new_label(pcVar8);
    tuple_insert_before(pcVar7,pcVar9);
    insert_fn = tuple_insert_before;
    pcVar11 = operand_new_intconst(0x1004,object->guard_bit,0);
    pcVar10 = operand_new_sym(0x14a,0x1004,object->guard_word);
    pcVar7 = tuple_new_binary_temp(0x172,0x1004,pcVar10,pcVar11,insert_fn,pcVar6);
    insert_fn = tuple_insert_after;
    pcVar6 = pcVar7;
    pcVar11 = operand_new_intconst(0x1004,0,0);
    tuple_new_compare(0x17d,0x1004,pcVar7->dst,pcVar11,insert_fn,pcVar6);
    pcVar6 = pcVar7->next;
    tuple_new_branch(0x185,'\x01',(c2_node *)pcVar9,pcVar6->dst,pcVar6,tuple_insert_after,pcVar6);
  }
  pcVar4 = funclet_fn->cfg;
  object->funclet_label = (c2_fe_symbol *)funclet_label->src;
  dtor_body = (c2_tuple *)0x0;
  tuple_range_clear_line(pcVar4->first->head,pcVar4->last->end);
  object->funclet = funclet_fn;
  funclet_fn->funclet_refs = 1;
LAB_107546e9:
  if (guarded != 0) {
    pcVar10 = operand_new_sym(0x14a,0x1004,object->guard_word);
    insert_fn = tuple_insert_before;
    pcVar6 = t;
    pcVar11 = operand_new_intconst(0x1004,object->guard_bit,0);
    pcVar6 = tuple_new_binary_temp(0x173,0x1004,pcVar10,pcVar11,insert_fn,pcVar6);
    tuple_new(0x15b,0x1004,pcVar10,pcVar6->dst,tuple_insert_after,pcVar6);
  }
  if (dtor_body != (c2_tuple *)0x0) {
    node_list_free((c2_node *)dtor_body);
  }
  pcVar10 = t->dst;
  ((t->u20).eh_construct)->object = object;
  if (((pcVar10 != (c2_operand *)0x0) && ((1 << (pcVar10->kind & 0x1f) & 6U) != 0)) &&
     (pcVar10->sym->def != (c2_tuple *)0x0)) {
    reader_spill_eh_value(t);
  }
  return;
}

