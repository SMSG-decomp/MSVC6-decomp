int __fastcall sizeopt_backward_scan(c2_block *block)

{
  byte bVar1;
  ushort uVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *t;
  int iVar7;
  uint32_t uVar8;
  uint uVar9;
  uint uVar10;
  int local_c;
  c2_tuple *local_8;
  
  pcVar3 = block->head;
  local_c = 0;
  local_8 = block->end;
joined_r0x10719461:
  do {
    while( true ) {
      do {
        t = local_8;
        if (t == pcVar3) {
          return local_c;
        }
        local_8 = t->prev;
        bVar1 = t->kind;
      } while (((bVar1 == 0xd) ||
               ((((0x10 < bVar1 && (bVar1 < 0x1c)) || ((t->type & 0xf000) == 0x4000)) ||
                (4 < (t->type & 0xfff))))) ||
              (((pcVar4 = t->src, pcVar4 != (c2_operand *)0x0 && (4 < (pcVar4->type & 0xfff))) ||
               ((pcVar4->type & 0xf000) == 0x4000))));
      uVar2 = t->line;
      if (uVar2 != 0) {
        g_current_line_abs = g_cur_function->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      for (; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
        if ((((1 << (pcVar4->kind & 0x1f) & 6U) != 0) &&
            (pcVar5 = pcVar4->sym, pcVar5->def != (c2_tuple *)0x0)) &&
           (((1 << (byte)(pcVar4->type >> 0xc) & 0xeU) != 0 &&
            ((iVar7 = (pcVar4->type & 0xfff) + pcVar5->offset, iVar7 < 3 && (t->op != 0x178)))))) {
          pcVar5 = pcVar5->storage;
          if (iVar7 == 1) {
            for (; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next) {
              if (pcVar5->offset == 0) {
                (pcVar5->u30).globopt.killed = '\x18';
              }
            }
          }
          else {
            for (; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next) {
              if (pcVar5->offset == 0) {
                (pcVar5->u30).globopt.killed = '\x10';
              }
            }
          }
        }
      }
      iVar7 = sizeopt_dead_high_bits(t);
      if ((iVar7 != 0) && ((1 << (t->src->kind & 0x1f) & 6U) != 0)) {
        for (pcVar5 = t->src->sym->storage; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next)
        {
          if (pcVar5->offset == 0) {
            (pcVar5->u30).globopt.killed = (uint8_t)iVar7;
          }
        }
      }
      uVar8 = sizeopt_result_known_bits(t);
      if ((uVar8 != 0) && (pcVar4 = t->src->next, (1 << (pcVar4->kind & 0x1f) & 6U) != 0)) {
        for (pcVar5 = pcVar4->sym->storage; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next)
        {
          if (pcVar5->offset == 0) {
            (pcVar5->u30).globopt.killed = (uint8_t)uVar8;
          }
        }
      }
      if (t->op != 0x15f) break;
      uVar2 = t->src->type;
      if (((((1 << (byte)(uVar2 >> 0xc) & 0xeU) == 0) || ((uVar2 & 0xfff) != 2)) ||
          ((1 << (t->dst->kind & 0x1f) & 6U) == 0)) ||
         ((pcVar5 = t->dst->sym, pcVar5->def == (c2_tuple *)0x0 ||
          ((pcVar5->u30).globopt.killed < 0x10)))) {
        uVar2 = t->src->type;
        if (((((1 << (byte)(uVar2 >> 0xc) & 0xeU) == 0) ||
             (((uVar2 & 0xfff) != 1 || ((1 << (t->dst->kind & 0x1f) & 6U) == 0)))) ||
            (pcVar5 = t->dst->sym, pcVar5->def == (c2_tuple *)0x0)) ||
           ((pcVar5->u30).globopt.killed < 0x18)) break;
        remove_redundant_extension(t);
        local_c = 1;
      }
      else {
        remove_redundant_extension(t);
        local_c = 1;
      }
    }
  } while (t->dst == (c2_operand *)0x0);
  if (t->op == 0x15b) {
    local_8 = tuple_prev_of(t);
  }
  if (((((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) &&
      (1 < (t->type & 0xfff))) &&
     ((iVar7 = can_change_op_width(t,1), iVar7 != 0 && (iVar7 = op_supports_width(t,1), iVar7 != 0))
     )) {
    set_op_width(t,1);
    local_c = 1;
  }
  if ((((t->type & 0xfff) < 4) && (iVar7 = can_change_op_width(t,4), iVar7 != 0)) &&
     (iVar7 = op_supports_width(t,4), iVar7 != 0)) {
    set_op_width(t,4);
    local_c = 1;
  }
  pcVar4 = t->dst;
  uVar10 = 1 << (pcVar4->kind & 0x1f) & 6;
  if ((((uVar10 != 0) && (pcVar4->sym->def != (c2_tuple *)0x0)) && (t->op == 0x172)) &&
     (pcVar6 = t->src->next, pcVar6->kind == '\a')) {
    bVar1 = (pcVar4->sym->u30).globopt.killed;
    if (bVar1 < 0x18) {
      uVar9 = (-(uint)(bVar1 < 0x10) & 0xffff0000) + 0xffff;
    }
    else {
      uVar9 = 0xff;
    }
    if (((pcVar6->u18).lo & uVar9) == uVar9) {
      remove_redundant_extension(t);
      local_c = 1;
      goto joined_r0x10719461;
    }
  }
  if (((uVar10 != 0) && (pcVar4->sym->def != (c2_tuple *)0x0)) &&
     (((pcVar4->sym->u30).globopt.killed != '\0' && (iVar7 = sizeopt_def_known_bits(t), iVar7 != 0))
     )) {
    for (pcVar4 = t->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
      if ((((pcVar4->flags & 0x20) == 0) && ((1 << (pcVar4->kind & 0x1f) & 6U) != 0)) &&
         ((pcVar5 = pcVar4->sym, pcVar5->def != (c2_tuple *)0x0 &&
          ((pcVar5->offset == 0 && ((int)(uint)(pcVar5->u30).globopt.killed < iVar7)))))) {
        for (pcVar5 = pcVar5->storage; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next) {
          if (pcVar5->offset == 0) {
            (pcVar5->u30).globopt.killed = (uint8_t)iVar7;
          }
        }
      }
    }
  }
  goto joined_r0x10719461;
}

