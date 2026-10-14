void __fastcall add_reference_saving(c2_tuple *t,c2_live_range *lr,c2_block *b)

{
  c2_symbol_cell **ppcVar1;
  c2_symbol *sym;
  c2_operand *k;
  uint32_t uVar2;
  int iVar3;
  c2_operand *pcVar4;
  
  pcVar4 = t->dst;
  if (((((pcVar4->kind == '\x01') && (((pcVar4->u18).reg)->cls == '\x02')) &&
       ((pcVar4->u18).reg != (c2_symbol *)lr)) ||
      (((pcVar4 = t->src, pcVar4->kind == '\x01' && (((pcVar4->u18).reg)->cls == '\x02')) &&
       ((pcVar4->u18).reg != (c2_symbol *)lr)))) ||
     (((pcVar4 = pcVar4->next, pcVar4 != (c2_operand *)0x0 && (pcVar4->kind == '\x01')) &&
      ((((pcVar4->u18).reg)->cls == '\x02' && ((pcVar4->u18).reg != (c2_symbol *)lr)))))) {
    sym = pcVar4->sym;
    if (sym->cls == '\r') {
      if (g_opt_favor_speed != 0) {
        ((pcVar4->u18).reg)->copy_equivs =
             (c2_symbol_cell *)
             ((int)&((pcVar4->u18).reg)->copy_equivs->next + (1 << ((byte)b->loop_depth & 0x1f)));
        return;
      }
      k = (sym->u28).const_operand;
      if (k->kind == '\a') {
        if ((k->u18).reg == (c2_symbol *)0x0) {
          if ((t->op == 1) || (t->op == 0x2f)) {
            ((pcVar4->u18).reg)->copy_equivs =
                 (c2_symbol_cell *)((int)&((pcVar4->u18).reg)->copy_equivs->next + 1);
            return;
          }
        }
        else {
          iVar3 = const_compare(k,0xffffffff,-1);
          if ((((iVar3 != 0) && (t->op == 1)) && ((t->type & 0xfff) == 4)) &&
             ((c2_symbol *)(int)*(char *)&k->u18 == (k->u18).reg)) {
            ((pcVar4->u18).reg)->copy_equivs =
                 (c2_symbol_cell *)((int)&((pcVar4->u18).reg)->copy_equivs->next + 2);
            return;
          }
        }
      }
    }
    else {
      uVar2 = memory_operand_saving(t,sym);
      iVar3 = load_saving(pcVar4->sym);
      iVar3 = iVar3 - uVar2;
      if (g_opt_favor_speed != 0) {
        iVar3 = iVar3 * (1 << ((byte)b->loop_depth & 0x1f));
      }
      ppcVar1 = &((pcVar4->u18).reg)->copy_equivs;
      *ppcVar1 = (c2_symbol_cell *)((int)&(*ppcVar1)->next + iVar3);
    }
  }
  return;
}

