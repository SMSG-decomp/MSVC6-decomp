void __fastcall reader_load_value(c2_reader_cell *cell,uint16_t type,int size,int volatile_bits)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_symbol *pcVar4;
  uint32_t id;
  c2_operand *local_4;
  
  local_4 = (c2_operand *)cell;
  if ((cell->flags & 4) != 0) {
    reader_load_bitfield(cell,type,volatile_bits);
    return;
  }
  local_4 = reader_pop_operand(cell);
  if ((local_4->type & 0xf000) != 0x3000) {
    convert_operand(&local_4,0x3004,&cell->tail);
  }
  if ((local_4->flags & 0x10) != 0) {
    local_4 = (c2_operand *)node_clone((c2_node *)local_4);
  }
  switch(local_4->kind) {
  case '\x02':
    goto override_jmp_107307e1_case_1;
  case '\x03':
    if (g_opt_dlp != 0) {
      uVar1 = local_4->sym->cls;
      if (((uVar1 == '\a') || (uVar1 == '\b')) || ((type & 0xf000) == 0x5000)) {
        id = local_4->sym->fe->cv_type_index;
        if (id == 0) {
          id = dlp_type_code(type);
        }
        pcVar3 = tuple_new_unary_temp(0x15b,0x3004,local_4,tuple_splice_after,cell->tail);
        local_4 = operand_new_mem(0x14c,type,(c2_symbol *)0x0,0,pcVar3->dst,(c2_operand *)0x0,0);
        cell->tail = pcVar3;
        pcVar4 = (c2_symbol *)dlp_pack_site_id(0,0,id);
        local_4->sym = pcVar4;
        break;
      }
    }
    operand_to_memory_form(local_4);
    local_4->type = type;
    if (local_4->kind == '\x02') {
      pcVar4 = local_4->sym->storage;
      pcVar4 = symbol_get_part(pcVar4,type,size,local_4->sym->offset - pcVar4->offset);
      local_4->sym = pcVar4;
    }
    break;
  case '\x04':
    pcVar3 = tuple_new_unary_temp(0x15b,0x3004,local_4,tuple_splice_after,cell->tail);
    local_4 = operand_new_mem(0x14c,type,(c2_symbol *)0x0,0,pcVar3->dst,(c2_operand *)0x0,0);
    cell->tail = pcVar3;
    break;
  case '\x06':
    pcVar3 = tuple_new_unary_temp(0x15b,0x3004,local_4,tuple_splice_after,cell->tail);
    cell->tail = pcVar3;
    local_4 = pcVar3->dst;
  case '\x01':
    if (((((g_opt_dlp == 0) && ((1 << (local_4->kind & 0x1f) & 6U) != 0)) &&
         ((pcVar3 = local_4->sym->def, pcVar3 != (c2_tuple *)0x0 &&
          ((pcVar3->op == 0x16d && (pcVar3->src->kind == '\x03')))))) &&
        (pcVar2 = pcVar3->src->next, pcVar2->kind == '\a')) && (-1 < (int)(pcVar2->u18).reg)) {
      node_free((c2_node *)local_4);
      pcVar2 = pcVar3->src;
      pcVar4 = symbol_get_part(pcVar2->sym,type,size,(pcVar2->next->u18).lo);
      local_4 = operand_new_sym(pcVar2->op,type,pcVar4);
      if (cell->tail == pcVar3) {
        cell->tail = pcVar3->prev;
      }
      tuple_unlink(pcVar3);
      node_free((c2_node *)pcVar3);
    }
    else {
override_jmp_107307e1_case_1:
      local_4 = operand_new_mem(0x14c,type,(c2_symbol *)0x0,0,local_4,(c2_operand *)0x0,0);
    }
  }
  tuple_splice_after(cell->tail,(c2_tuple *)local_4);
  cell->tail = (c2_tuple *)local_4;
  if (volatile_bits == 0) {
    return;
  }
  local_4->flags = local_4->flags | 0x40;
  return;
}

