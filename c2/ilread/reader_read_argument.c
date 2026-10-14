void __fastcall reader_read_argument(c2_reader_cell *cell,c2_reader_op *op)

{
  c2_tuple **anchor;
  ushort uVar1;
  uint16_t uVar2;
  c2_symbol *pcVar3;
  int lo;
  c2_tuple *pcVar4;
  c2_const_operand *size;
  c2_operand *pcVar5;
  ushort uVar6;
  int hi;
  ushort uVar7;
  c2_operand *local_8;
  c2_reader_op *local_4;
  
  local_4 = op;
  local_8 = reader_pop_operand(cell);
  uVar7 = op->type;
  uVar1 = local_8->type;
  if (uVar7 == 0) {
    uVar7 = uVar1;
    if ((1 << (byte)(uVar1 >> 0xc) & 0xeU) == 0) {
      uVar6 = uVar1 & 0xf000;
      if (uVar6 == 0x4000) {
        if ((uVar1 & 0xfff) < 9) {
          uVar7 = 0x4008;
        }
        else {
          uVar7 = uVar1 & 0xfff | 0x4000;
        }
      }
      else if (uVar6 == 0x3000) {
        if ((uVar1 & 0xfff) < 5) {
          uVar7 = 0x3004;
        }
        else {
          uVar7 = uVar1 & 0xfff | 0x3000;
        }
      }
      else if (uVar6 == 0x5000) {
        local_4->size = g_reader_aggregate_size;
      }
    }
    else if ((uVar1 & 0xfff) < 5) {
      uVar7 = uVar1 & 0xf000 | 4;
    }
  }
  else if ((((1 << (byte)(uVar7 >> 0xc) & 0xeU) != 0) && ((uVar7 & 0xfff) < (uVar1 & 0xfff))) &&
          ((1 << (local_8->kind & 0x1f) & 0x380U) == 0)) {
    warning(1,0x2f9);
  }
  if ((uVar7 & 0xf000) == 0x5000) {
    g_reader_aggregate_size = local_4->size;
    if (cell->after != (c2_reader_cell *)0x0) {
      tuple_splice_after(cell->tail,(c2_tuple *)local_8);
      cell->tail = (c2_tuple *)local_8;
      reader_address_of_top(cell,g_ptr_type);
      local_8 = reader_pop_operand(cell);
      pcVar5 = operand_new_temp_sym(g_ptr_type);
      pcVar5->sym->flags7 = pcVar5->sym->flags7 | 2;
      pcVar4 = tuple_new(0x15b,g_ptr_type,pcVar5,local_8,tuple_splice_after,cell->tail);
      cell->tail = pcVar4;
      reader_load_value(cell,uVar7,g_reader_aggregate_size,0);
      local_8 = reader_pop_operand(cell);
    }
    if ((((1 << (local_8->kind & 0x1f) & 6U) == 0) ||
        (pcVar4 = local_8->sym->def, pcVar4 == (c2_tuple *)0x0)) ||
       ((pcVar4->kind != '\x12' ||
        ((uVar2 = (pcVar4->u20).intrinsic.id, uVar2 != 0xde && (uVar2 != 0xdf)))))) {
      if (0xfff < g_reader_aggregate_size) {
        tuple_splice_after(cell->tail,(c2_tuple *)local_8);
        cell->tail = (c2_tuple *)local_8;
        reader_address_of_top(cell,g_ptr_type);
        pcVar5 = reader_pop_operand(cell);
        pcVar4 = tuple_new_unary_temp(0x15a,g_ptr_type,pcVar5,tuple_splice_after,cell->tail);
        lo = g_reader_aggregate_size;
        hi = g_reader_aggregate_size >> 0x1f;
        cell->tail = pcVar4;
        local_8 = operand_new_intconst(0x1004,lo,hi);
        local_8 = (c2_operand *)
                  tuple_new_unary_temp(0x15a,g_ptr_type,local_8,tuple_splice_after,pcVar4);
        cell->tail = (c2_tuple *)local_8;
        pcVar4 = tuple_new_intrinsic_result
                           (400,g_ptr_type,pcVar4->dst,(c2_operand *)local_8->tag,(c2_operand *)0x0,
                            (c2_operand *)0x0,0x184,tuple_splice_after,(c2_tuple *)local_8);
        uVar2 = g_ptr_type;
        pcVar5 = pcVar4->dst;
        cell->tail = pcVar4;
        pcVar4 = tuple_new_unary_temp(0x15a,uVar2,pcVar5,tuple_splice_after,pcVar4);
        cell->tail = pcVar4;
        return;
      }
    }
    else if (0xfff < g_reader_aggregate_size) {
      g_reader_aggregate_size = 0;
    }
    pcVar5 = operand_new_temp_sym(uVar7);
    size = operand_new_intconst(0x1004,g_reader_aggregate_size,g_reader_aggregate_size >> 0x1f);
    pcVar4 = tuple_new_blockop(0x16a,uVar7,pcVar5,local_8,size,tuple_splice_after,cell->tail);
    pcVar3 = pcVar5->sym;
    cell->tail = pcVar4;
    pcVar3->def = pcVar4;
    return;
  }
  anchor = &cell->tail;
  convert_operand(&local_8,uVar7,anchor);
  if (cell->after != (c2_reader_cell *)0x0) {
    pcVar5 = operand_new_temp_sym(uVar7);
    pcVar4 = *anchor;
    pcVar5->sym->flags7 = pcVar5->sym->flags7 | 2;
    pcVar4 = tuple_new(0x15b,uVar7,pcVar5,local_8,tuple_splice_after,pcVar4);
    *anchor = pcVar4;
    local_8 = pcVar5;
  }
  pcVar4 = tuple_new_unary_temp(0x15a,uVar7,local_8,tuple_splice_after,*anchor);
  *anchor = pcVar4;
  return;
}

