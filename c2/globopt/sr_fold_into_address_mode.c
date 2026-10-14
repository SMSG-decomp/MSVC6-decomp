int __fastcall
sr_fold_into_address_mode
          (c2_tuple *t,c2_operand *mem,c2_operand *old,int op,c2_operand *a,c2_operand *b,int apply)

{
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  byte bVar3;
  int iVar4;
  
  if (mem->op == 0x14c) {
    if (op == 0x16d) {
      bVar3 = b->kind;
      if ((1 << (bVar3 & 0x1f) & 6U) != 0) {
        if (apply != 0) {
          tuple_replace_src(t,old,b);
          pcVar2 = tuple_append_src(t,a);
          mem->index = pcVar2;
          pcVar2->flags = pcVar2->flags | 0x20;
          mem->op = 0x14d;
          symbol_add_use_unique(pcVar2->sym,t);
        }
        return 1;
      }
      if (bVar3 == 7) {
        if (apply != 0) {
          tuple_replace_src(t,old,a);
          mem->disp = (int)&((b->u18).reg)->fe + mem->disp;
          symbol_add_use_unique(a->sym,t);
        }
        return 1;
      }
      if ((bVar3 == 3) && (mem->base_sym == (c2_symbol *)0x0)) {
        if (apply != 0) {
          tuple_replace_src(t,old,a);
          mem->base_sym = b->sym;
          symbol_add_use_unique(a->sym,t);
        }
        return 1;
      }
    }
    else if (((op == 0x16f) && (b->kind == '\a')) &&
            (((pcVar1 = (b->u18).reg, pcVar1 == (c2_symbol *)0x1 ||
              ((pcVar1 == (c2_symbol *)0x2 || (pcVar1 == (c2_symbol *)0x4)))) ||
             (pcVar1 == (c2_symbol *)0x8)))) {
      if (apply != 0) {
        tuple_replace_src(t,old,a);
        if ((int)(b->u18).reg < 8) {
          bVar3 = (byte)((int)(b->u18).reg >> 1);
        }
        else {
          bVar3 = 3;
        }
        mem->op = 0x14f;
        mem->flags = (mem->flags ^ bVar3) & 0xf ^ mem->flags;
        mem->index = mem->base;
        mem->base = (c2_operand *)0x0;
        symbol_add_use_unique(a->sym,t);
      }
      return 1;
    }
  }
  else if (mem->op == 0x14d) {
    if (op == 0x16d) {
      if (b->kind == '\a') {
        if (apply != 0) {
          tuple_replace_src(t,old,a);
          mem->disp = (int)&((b->u18).reg)->fe + mem->disp;
          symbol_add_use_unique(a->sym,t);
        }
        return 1;
      }
      if ((b->kind == '\x03') && (mem->base_sym == (c2_symbol *)0x0)) {
        if (apply != 0) {
          tuple_replace_src(t,old,a);
          mem->base_sym = b->sym;
          symbol_add_use_unique(a->sym,t);
        }
        return 1;
      }
    }
    else if ((op == 0x16f) && (b->kind == '\a')) {
      pcVar1 = mem->base->sym;
      if (((old->sym != pcVar1) || ((mem->flags & 0xf) == 0)) &&
         ((((iVar4 = (1 << (mem->flags & 0xf)) * (b->u18).lo, iVar4 == 1 || (iVar4 == 2)) ||
           (iVar4 == 4)) || (iVar4 == 8)))) {
        if (apply != 0) {
          if (old->sym == pcVar1) {
            pcVar2 = mem->index;
            mem->index = mem->base;
            mem->base = pcVar2;
          }
          tuple_replace_src(t,old,a);
          if (iVar4 < 8) {
            bVar3 = (byte)(iVar4 >> 1);
          }
          else {
            bVar3 = 3;
          }
          mem->flags = (mem->flags ^ bVar3) & 0xf ^ mem->flags;
          symbol_add_use_unique(a->sym,t);
        }
        return 1;
      }
    }
  }
  return 0;
}

