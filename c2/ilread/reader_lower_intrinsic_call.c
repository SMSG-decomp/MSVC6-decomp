c2_tuple * __fastcall reader_lower_intrinsic_call(c2_function *fn,c2_tuple *call)

{
  uint8_t *puVar1;
  uint32_t uVar2;
  uint16_t uVar3;
  c2_operand *src;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  c2_symbol *pcVar6;
  c2_fe_symbol *sym;
  c2_operand *pcVar7;
  c2_tuple *pcVar8;
  c2_tuple *local_c;
  c2_operand *local_8;
  c2_function *local_4;
  
  uVar3 = g_ptr_type;
  local_c = call;
  local_4 = fn;
  switch((call->u20).intrinsic.id) {
  case 0xa8:
    intrinsic_convert_arguments(call);
    reader_lower_eh_intrinsic(fn,local_c);
    local_8 = local_c->dst;
    pcVar8 = convert_operand(&local_8,0x1004,&local_c);
    return pcVar8;
  default:
    intrinsic_convert_arguments(call);
    break;
  case 0xac:
    intrinsic_convert_arguments(call);
    pcVar7 = local_c->src->next->next->sym->def->src;
    if ((1 << (pcVar7->kind & 0x1f) & 0x380U) != 0) {
      uVar2 = pcVar7->tag;
      if ((((pcVar7->u18).reg != (c2_symbol *)0x0 || uVar2 != 0) && ((int)uVar2 < 1)) &&
         (((int)uVar2 < 0 || ((pcVar7->u18).reg < (c2_symbol *)0x1000)))) {
        pcVar4 = operand_new_temp_sym(g_ptr_type);
        pcVar8 = local_c->src->sym->def;
        tuple_new(0x15b,g_ptr_type,pcVar4,pcVar8->src,tuple_insert_before,pcVar8);
        tuple_replace_src(pcVar8,pcVar8->src,pcVar4);
        tuple_remove_dst(local_c,local_c->dst);
        local_8 = reader_operand_as_aggregate_mem(pcVar8,(pcVar7->u18).lo);
        src = reader_operand_as_aggregate_mem(local_c->src->next->sym->def,(pcVar7->u18).lo);
        pcVar8 = tuple_new_blockop(0x16b,local_8->type,local_8,src,pcVar7,tuple_splice_after,local_c
                                  );
        tuple_free_src_defs(local_c);
        tuple_unlink_free(local_c);
        pcVar5 = (c2_tuple *)node_clone((c2_node *)pcVar4);
        tuple_splice_after(pcVar8,pcVar5);
        return pcVar5;
      }
    }
    break;
  case 0xde:
    pcVar8 = call->src->next->sym->def;
    pcVar7 = pcVar8->src;
    pcVar4 = operand_new_sym(0x14a,g_ptr_type,pcVar7->sym);
    tuple_replace_src(pcVar8,pcVar7,pcVar4);
    return call;
  case 0xdf:
    call->type = g_ptr_type;
    pcVar7 = call->src->next;
    pcVar7->type = uVar3;
    pcVar8 = pcVar7->sym->def;
    pcVar5 = tuple_new_unary_temp(0x15a,uVar3,pcVar8->src,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
    tuple_replace(pcVar8,(c2_node *)pcVar5);
    tuple_replace_src(local_c,pcVar7,pcVar5->dst);
    pcVar7 = pcVar5->src;
    pcVar8 = pcVar7->sym->def;
    symbol_free_chain(pcVar7->sym);
    uVar3 = g_ptr_type;
    local_8 = pcVar8->dst;
    pcVar8->type = g_ptr_type;
    local_8->type = uVar3;
    pcVar6 = symbol_new_temp(uVar3);
    pcVar6->def = pcVar8;
    local_8->sym = pcVar6;
    uVar3 = g_ptr_type;
    pcVar7->sym = pcVar6;
    (local_8->u18).reg = pcVar6;
    pcVar7->type = uVar3;
    (pcVar7->u18).reg = pcVar6;
    reader_lower_eh_intrinsic(local_4,local_c);
    return call;
  case 0x151:
    intrinsic_convert_arguments(call);
    local_8 = local_c->dst;
    pcVar7 = local_c->src->sym->def->src;
    if (pcVar7->kind == '\x03') {
      if (g_cur_function != (c2_function *)0x0) {
        fn = g_cur_function;
      }
      puVar1 = &pcVar7->sym->storage->flags6;
      *puVar1 = *puVar1 | ((byte)(fn->flags >> 0x10) & 1) << 2;
    }
    sym = fe_symbol_lookup_name("__CxxThrowException@8");
    sym->attrs = sym->attrs | 0x80;
    pcVar7 = operand_new_codeaddr(0x153,sym);
    pcVar8 = tuple_new_call(0x184,local_c->type,local_8,pcVar7,'\x10',tuple_insert_before,local_c);
    pcVar6 = local_8->sym;
    if (pcVar6->storage->part_next == (c2_symbol *)0x0) {
      pcVar6->def = pcVar8;
    }
    else {
      symbol_mark_overlapping_parts(pcVar6,pcVar8);
    }
    pcVar8->src->next = local_c->src;
    local_c->src = (c2_operand *)0x0;
    tuple_unlink(local_c);
    node_free((c2_node *)local_c);
    return pcVar8;
  }
  reader_lower_eh_intrinsic(fn,local_c);
  return call;
}

