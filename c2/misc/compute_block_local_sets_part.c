void __fastcall
compute_block_local_sets_part
          (c2_operand *opnd,uint32_t candidate_no,c2_symbol *sym,c2_bitset *killed,
          c2_bitset *available,c2_tuple *tuple,c2_bitset *first_ref,uint32_t tuple_op,
          c2_block *block,int candidate_count,c2_tuple *block_head)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  c2_bitset *src;
  c2_operand *pcVar4;
  c2_symbol_cell **ppcVar5;
  c2_symbol **ppcVar6;
  c2_bitset *bs;
  c2_bitset *bs_00;
  uint32_t uVar7;
  c2_tuple *pcVar8;
  uint32_t uVar9;
  c2_symbol *pcVar10;
  c2_symbol_cell *pcVar11;
  c2_operand *op;
  c2_block *pcVar12;
  c2_symbol_cell *pcVar13;
  c2_symbol_cell *pcVar14;
  c2_symbol *sym_00;
  
LAB_1071b043:
  bitset_clear(available,candidate_no);
  pcVar10 = sym->storage;
  if (pcVar10->part_next == (c2_symbol *)0x0) goto switchD_1071afc3_caseD_3;
LAB_1071b05a:
  for (pcVar10 = pcVar10->storage; pcVar10 != (c2_symbol *)0x0; pcVar10 = pcVar10->part_next) {
    if (sym != pcVar10) {
      if ((((sym->offset < pcVar10->size + pcVar10->offset) &&
           (pcVar10->offset < sym->size + sym->offset)) &&
          ((pcVar10->u30).ra != (c2_ra_candidate *)0x0)) &&
         (uVar9 = ((pcVar10->u30).ra)->id, uVar9 != 0)) {
        bitset_set(killed,uVar9);
        bitset_clear(available,uVar9);
      }
    }
  }
switchD_1071afc3_caseD_3:
  opnd = opnd->next;
  bs_00 = killed;
  bs = available;
  pcVar12 = block;
  pcVar8 = block_head;
  while (killed = bs_00, available = bs, block_head = pcVar8, opnd == (c2_operand *)0x0) {
    for (op = tuple->src; op != (c2_operand *)0x0; op = op->next) {
      if (op->kind == '\x01') {
        bVar1 = op->flags;
        op->flags = bVar1 & 0xf0;
        if ((op->u18).reg == &g_register_candidate_home) {
          pcVar10 = (op->sym->u34).parent;
          sym_00 = op->sym;
          if (pcVar10 != (c2_symbol *)0x0) {
            sym_00 = pcVar10;
          }
          uVar9 = ((sym_00->u30).ra)->id;
          g_candidate_symbols[uVar9] = sym_00;
          if (((sym_00->cls == '\r') && ((sym_00->flags5 & 0x10) == 0)) &&
             ((block->loop == (c2_loop *)0x0 || (g_opt_favor_speed == 0)))) {
            op = tuple_replace_src_with_base_copy(tuple,op,sym_00);
          }
          else if ((((tuple->type & 0xf000) == 0x4000) ||
                   (((uVar3 = tuple->op, uVar3 != 0 && (uVar3 < 0x144)) &&
                    ((g_x86_op_flags[uVar3] & 1) != 0)))) && ((bVar1 & 0x20) == 0)) {
            operand_make_sym(op);
            if (sym_00->cls == '\x03') {
              sym_00->flags6 = sym_00->flags6 | 2;
            }
          }
          else {
            uVar7 = bitset_test(bs_00,uVar9);
            if (uVar7 == 0) {
              bitset_set(first_ref,uVar9);
            }
LAB_1071af42:
            bitset_set(bs,uVar9);
          }
        }
      }
      else if (op->kind == '\x02') {
        pcVar10 = op->sym;
        if ((((pcVar10->u30).order_prev != (c2_symbol *)0x0) &&
            (((pcVar10->u30).order_prev)->fe != (c2_fe_symbol *)0x0)) && ((op->flags & 0x40) == 0))
        {
          if ((((tuple->type & 0xf000) == 0x4000) ||
              (((uVar3 = tuple->op, uVar3 != 0 && (uVar3 < 0x144)) &&
               ((g_x86_op_flags[uVar3] & 1) != 0)))) &&
             (((op->flags & 0x20) == 0 && ((pcVar10->type & 0xf000) != 0x4000)))) {
            if (pcVar10->cls == '\x03') {
              pcVar10->flags6 = pcVar10->flags6 | 2;
            }
          }
          else {
            pcVar4 = tuple->dst;
            if ((pcVar4 == (c2_operand *)0x0) ||
               (((pcVar4->kind != '\x02' || ((pcVar4->flags & 0x40) == 0)) ||
                (pcVar4->sym != pcVar10)))) {
              set_operand_home(op,&g_register_candidate_home);
              ppcVar6 = g_candidate_symbols;
              op->flags = op->flags & 0xf0;
              uVar9 = ((pcVar10->u30).ra)->id;
              ppcVar6[uVar9] = pcVar10;
              uVar7 = bitset_test(bs_00,uVar9);
              if (uVar7 == 0) {
                bitset_set(first_ref,uVar9);
              }
              goto LAB_1071af42;
            }
          }
        }
      }
      pcVar12 = block;
    }
    mark_tied_operand_pair(tuple);
    do {
      tuple = tuple->prev;
      if (tuple == pcVar8) {
        do {
          pcVar12->ue = bs;
          pcVar12->de = first_ref;
          pcVar12->kill = bs_00;
          pcVar12 = pcVar12->next;
          if (pcVar12 == (c2_block *)0x0) {
            return;
          }
          first_ref = bitset_new(6);
          bs = bitset_new(6);
          bs_00 = bitset_new(6);
          tuple = pcVar12->end;
          pcVar8 = pcVar12->head;
          killed = bs_00;
          available = bs;
          block = pcVar12;
          block_head = pcVar8;
        } while (tuple == pcVar8);
      }
    } while ((tuple->flags & 1) == 0);
    if ((tuple->kind == '\x14') || (tuple_op = tuple->op, tuple_op == 0x187)) {
      tuple_op = tuple->op;
      switch(tuple_op) {
      case 0x187:
      case 0x194:
      case 0x196:
      case 0x198:
      case 0x19a:
      case 0x19c:
      case 0x1a5:
switchD_1071ae55_caseD_187:
        bitset_set_range(bs_00,candidate_count + 1);
        bitset_clear_all(bs);
        break;
      case 0x19d:
        if (((tuple->u20).cc & 1) != 0) goto switchD_1071ae55_caseD_187;
        if ((((tuple->u20).cc & 2) != 0) && (uVar9 = 1, g_candidate_count != 0)) {
          do {
            bitset_set(killed,uVar9);
            bitset_clear(bs,uVar9);
            uVar9 = uVar9 + 1;
          } while (uVar9 <= g_candidate_count);
        }
      }
    }
    bs_00 = killed;
    bs = available;
    pcVar8 = block_head;
    opnd = tuple->dst;
  }
  switch(opnd->kind) {
  case '\x01':
    opnd->flags = opnd->flags & 0xf0;
    if ((opnd->u18).reg == &g_register_candidate_home) {
      pcVar10 = (opnd->sym->u34).parent;
      sym = opnd->sym;
      if (pcVar10 != (c2_symbol *)0x0) {
        sym = pcVar10;
      }
      candidate_no = ((sym->u30).ra)->id;
      uVar2 = tuple->type;
      g_candidate_symbols[candidate_no] = sym;
      if (((uVar2 & 0xf000) == 0x4000) ||
         (((tuple_op != 0 && (tuple_op < 0x144)) && ((g_x86_op_flags[tuple_op] & 1) != 0)))) {
        operand_make_sym(opnd);
        bitset_set(bs_00,candidate_no);
        if (sym->cls == '\x03') {
          sym->flags6 = sym->flags6 | 2;
        }
      }
      else {
        uVar9 = bitset_test(bs_00,candidate_no);
        if (uVar9 == 0) {
          bitset_set(first_ref,candidate_no);
          bitset_set(bs_00,candidate_no);
        }
      }
      goto LAB_1071b043;
    }
    goto switchD_1071afc3_caseD_3;
  case '\x02':
    sym = opnd->sym;
    if (((sym->u30).ra != (c2_ra_candidate *)0x0) && (uVar9 = ((sym->u30).ra)->id, uVar9 != 0)) {
      if (((opnd->flags & 0x40) == 0) &&
         (((((tuple->type & 0xf000) != 0x4000 &&
            (((tuple_op == 0 || (0x143 < tuple_op)) || ((g_x86_op_flags[tuple_op] & 1) == 0)))) ||
           ((sym->type & 0xf000) == 0x4000)) && ((tuple_op != 0x5b && (tuple_op != 0x5a)))))) {
        set_operand_home(opnd,&g_register_candidate_home);
        ppcVar6 = g_candidate_symbols;
        uVar9 = ((sym->u30).ra)->id;
        opnd->flags = opnd->flags & 0xf0;
        ppcVar6[uVar9] = sym;
        uVar7 = bitset_test(bs_00,uVar9);
        if (uVar7 == 0) {
          bitset_set(first_ref,uVar9);
          bitset_set(bs_00,uVar9);
        }
        bitset_clear(bs,uVar9);
        goto LAB_1071b130;
      }
      bitset_set(bs_00,uVar9);
      candidate_no = ((sym->u30).ra)->id;
      goto LAB_1071b043;
    }
LAB_1071b130:
    pcVar10 = sym->storage;
    if (pcVar10->part_next != (c2_symbol *)0x0) goto LAB_1071b05a;
  default:
    goto switchD_1071afc3_caseD_3;
  case '\x06':
    pcVar10 = (c2_symbol *)opnd->tag;
    break;
  case '\v':
    pcVar10 = opnd->sym;
  }
  pcVar11 = alias_class_members((uint32_t)pcVar10);
  pcVar13 = (c2_symbol_cell *)0x0;
joined_r0x1071b1bd:
  if (pcVar11 != (c2_symbol_cell *)0x0) {
    do {
      pcVar10 = pcVar11->sym;
      pcVar14 = pcVar11;
      if (pcVar10->cls == '\f') {
        pcVar14 = (pcVar10->u30).members;
        pcVar13 = pcVar11;
        if (pcVar14 == (c2_symbol_cell *)0x0) {
          pcVar11 = pcVar11->next;
          goto joined_r0x1071b1bd;
        }
        pcVar10 = pcVar14->sym;
      }
      if (((pcVar10->u30).ra != (c2_ra_candidate *)0x0) &&
         (src = ((pcVar10->u30).ra)->part_ids, src != (c2_bitset *)0x0)) {
        bitset_or(bs_00,src);
        bitset_andnot(bs,((pcVar10->u30).ra)->part_ids);
      }
      pcVar11 = pcVar14->next;
    } while (pcVar11 != (c2_symbol_cell *)0x0);
    if (pcVar13 == (c2_symbol_cell *)0x0) goto switchD_1071afc3_caseD_3;
    ppcVar5 = &pcVar13->next;
    pcVar13 = (c2_symbol_cell *)0x0;
    pcVar11 = *ppcVar5;
    goto joined_r0x1071b1bd;
  }
  goto switchD_1071afc3_caseD_3;
}

