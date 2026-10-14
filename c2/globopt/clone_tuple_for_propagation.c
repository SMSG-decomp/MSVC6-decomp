c2_tuple * __fastcall
clone_tuple_for_propagation(c2_tuple *t,int strip_destinations,int call_defs_through_clobbers)

{
  uint8_t *puVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  bool bVar4;
  int iVar5;
  c2_tuple *t_00;
  uint uVar6;
  c2_operand *n;
  c2_operand *pcVar7;
  
  if ((strip_destinations == 0) && (iVar5 = node_has_side_effects((c2_node *)t), iVar5 != 0)) {
    return (c2_tuple *)0x0;
  }
  t_00 = (c2_tuple *)node_clone((c2_node *)t);
  pcVar7 = t_00->dst;
  if (strip_destinations == 0) {
    tuple_append_src(t_00,pcVar7);
  }
  else {
    while (pcVar7 != (c2_operand *)0x0) {
      pcVar2 = pcVar7->next;
      if (((1 << (pcVar7->kind & 0x1f) & 0x60U) != 0) &&
         (pcVar3 = pcVar7->base, pcVar3 != (c2_operand *)0x0)) {
        pcVar3->flags = pcVar3->flags & 0xdf;
        pcVar7->base = (c2_operand *)0x0;
      }
      tuple_remove_dst(t_00,pcVar7);
      pcVar7 = pcVar2;
    }
    if (t_00->kind == '\x11') {
      pcVar7 = t_00->src;
      (t_00->u20).cond_cells = (c2_cond_cell *)0x0;
      if ((pcVar7->kind == '\x04') && (*(int *)((int)&pcVar7->sym->u30 + 2) != 0)) {
        tuple_remove_src(t_00,pcVar7);
      }
    }
  }
  do {
    bVar4 = false;
    pcVar7 = t_00->src;
    if (t_00->src == (c2_operand *)0x0) {
      return t_00;
    }
    do {
      pcVar2 = pcVar7->next;
      uVar6 = 1 << (pcVar7->kind & 0x1f);
      if (((uVar6 & 6) == 0) ||
         (pcVar3 = (c2_operand *)pcVar7->sym->def, pcVar3 == (c2_operand *)0x0)) {
        if ((uVar6 & 0x60) != 0) {
          if (pcVar7->base != (c2_operand *)0x0) {
            puVar1 = &pcVar7->base->flags;
            *puVar1 = *puVar1 & 0xdf;
          }
          pcVar7->base = (c2_operand *)0x0;
        }
      }
      else {
        n = pcVar3;
        if ((pcVar3->kind == '\x0e') && (call_defs_through_clobbers != 0)) {
          n = *(c2_operand **)&pcVar3->u18;
        }
        iVar5 = node_has_side_effects((c2_node *)n);
        if (iVar5 != 0) {
          node_free((c2_node *)t_00);
          return (c2_tuple *)0x0;
        }
        tuple_remove_src(t_00,pcVar7);
        for (pcVar7 = (pcVar3->u18).children; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
          if ((pcVar7->flags & 0x20) == 0) {
            tuple_append_src(t_00,pcVar7);
          }
        }
        for (pcVar7 = (c2_operand *)pcVar3->tag; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next)
        {
          if (((1 << (pcVar7->kind & 0x1f) & 6U) == 0) || (pcVar7->sym->def == (c2_tuple *)0x0)) {
            tuple_append_dst(t_00,pcVar7);
          }
        }
        bVar4 = true;
      }
      pcVar7 = pcVar2;
    } while (pcVar2 != (c2_operand *)0x0);
    if (!bVar4) {
      return t_00;
    }
  } while( true );
}

