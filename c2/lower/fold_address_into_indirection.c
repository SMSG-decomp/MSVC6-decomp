void __fastcall fold_address_into_indirection(c2_tuple *t,c2_operand *opnd)

{
  byte bVar1;
  uint8_t uVar2;
  uint16_t type;
  c2_symbol *pcVar3;
  c2_tuple *from;
  c2_operand *pcVar4;
  int iVar5;
  c2_symbol *pcVar6;
  byte bVar7;
  c2_operand *b;
  c2_operand *b_00;
  c2_symbol *pcVar8;
  c2_tuple *local_20;
  uint32_t local_18;
  c2_symbol *local_14;
  c2_symbol *local_8;
  c2_operand *local_4;
  
  if (((opnd->base->kind == '\x01') && (pcVar3 = opnd->base->sym, pcVar3->cls == '\x03')) &&
     (from = pcVar3->def, from != (c2_tuple *)0x0)) {
    if (from->op == 0x2d) {
      b_00 = from->src;
      b = b_00->next;
      uVar2 = b->kind;
      if ((uVar2 != '\a') && (uVar2 != '\x01')) {
        return;
      }
      if ((from->type & 0xfff) != 4) {
        return;
      }
      if (uVar2 == '\a') {
        local_14 = (b->u18).reg;
        b = (c2_operand *)0x0;
        local_18 = 0x14c;
        local_8 = (c2_symbol *)0x0;
        bVar7 = 0;
      }
      else {
        local_14 = (c2_symbol *)0x0;
        local_18 = 0x14d;
        local_8 = (c2_symbol *)0x0;
        bVar7 = 0;
      }
    }
    else {
      if (from->op != 0x12) {
        return;
      }
      pcVar4 = from->src;
      if (pcVar4->kind != '\x05') {
        return;
      }
      if ((opnd->base_sym != (c2_symbol *)0x0) && (pcVar4->base_sym != (c2_symbol *)0x0)) {
        return;
      }
      local_14 = (c2_symbol *)pcVar4->disp;
      b_00 = pcVar4->base;
      b = pcVar4->index;
      local_8 = pcVar4->base_sym;
      local_18 = pcVar4->op;
      bVar7 = pcVar4->flags & 0xf;
    }
    pcVar3 = (opnd->base->u18).reg;
    pcVar4 = find_dst_reg_operand(pcVar3,t);
    local_20 = t;
    while (pcVar4 != (c2_operand *)0x0) {
      do {
        local_20 = local_20->next;
        pcVar4 = find_src_reg_operand(pcVar3,local_20);
      } while (pcVar4 == (c2_operand *)0x0);
      if ((pcVar4->flags & 0x20) == 0) {
        return;
      }
      pcVar4 = find_dst_reg_operand(pcVar3,local_20);
    }
    if ((((b_00 == (c2_operand *)0x0) ||
         ((((((b_00->u18).reg)->cls != '\x01' && (b_00->kind == '\x01')) &&
           (b_00->sym->cls == '\x03')) && (b_00->sym->def != (c2_tuple *)0x0)))) ||
        (iVar5 = operand_used_between(b_00,from,local_20,pcVar3), iVar5 == 0)) &&
       ((b == (c2_operand *)0x0 ||
        ((((((b->u18).reg)->cls != '\x01' && (b->kind == '\x01')) &&
          ((b->sym->cls == '\x03' && (b->sym->def != (c2_tuple *)0x0)))) ||
         (iVar5 = operand_used_between(b,from,local_20,pcVar3), iVar5 == 0)))))) {
      while( true ) {
        pcVar4 = opnd->base;
        pcVar4->flags = pcVar4->flags & 0xdf;
        tuple_remove_src(t,pcVar4);
        opnd->base = (c2_operand *)0x0;
        if (b_00 != (c2_operand *)0x0) {
          pcVar4 = tuple_append_src(t,b_00);
          bVar1 = pcVar4->flags;
          opnd->base = pcVar4;
          pcVar4->flags = bVar1 | 0x20;
        }
        if (b != (c2_operand *)0x0) {
          pcVar4 = tuple_append_src(t,b);
          bVar1 = pcVar4->flags;
          opnd->index = pcVar4;
          pcVar4->flags = bVar1 | 0x20;
          opnd->flags = (opnd->flags ^ bVar7) & 0xf ^ opnd->flags;
        }
        opnd->op = local_18;
        opnd->disp = (int)&local_14->fe + opnd->disp;
        if (local_8 != (c2_symbol *)0x0) {
          opnd->base_sym = local_8;
        }
        if (t == local_20) break;
        pcVar4 = find_dst_reg_operand(pcVar3,t);
        tuple_remove_dst(t,pcVar4);
        if (((b_00 != (c2_operand *)0x0) && (b_00->kind == '\x01')) &&
           ((b_00->sym->cls == '\x03' && (b_00->sym->def != (c2_tuple *)0x0)))) {
          pcVar8 = (b_00->u18).reg;
          pcVar6 = symbol_new_temp(b_00->type);
          pcVar4 = operand_new_reg(0x149,b_00->type,pcVar6,pcVar8);
          pcVar8 = pcVar4->sym;
          b_00->sym = pcVar8;
          pcVar8->def = t;
          tuple_append_dst(t,pcVar4);
        }
        if ((((b != (c2_operand *)0x0) && (b->kind == '\x01')) && (b->sym->cls == '\x03')) &&
           (b->sym->def != (c2_tuple *)0x0)) {
          type = b->type;
          pcVar8 = (b->u18).reg;
          pcVar6 = symbol_new_temp(type);
          pcVar4 = operand_new_reg(0x149,type,pcVar6,pcVar8);
          pcVar8 = pcVar4->sym;
          b->sym = pcVar8;
          pcVar8->def = t;
          tuple_append_dst(t,pcVar4);
        }
        t = t->next;
        pcVar4 = find_src_reg_operand(pcVar3,t);
        while (pcVar4 == (c2_operand *)0x0) {
          t = t->next;
          pcVar4 = find_src_reg_operand(pcVar3,t);
        }
        opnd = find_mem_operand_using(t,pcVar4,&local_4);
      }
      tuple_unlink_free(from);
    }
  }
  return;
}

