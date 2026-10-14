int __fastcall merge_tails_tree_compare(c2_node *a,c2_node *b)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint32_t uVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  c2_operand *pcVar8;
  c2_operand *pcVar9;
  int iVar10;
  uint uVar11;
  c2_operand *pcVar12;
  uint uVar13;
  c2_operand *pcVar14;
  c2_node *pcVar15;
  c2_node *pcVar16;
  
  if (a == b) {
    return 0;
  }
  while( true ) {
    if (a == (c2_node *)0x0) {
      return -1;
    }
    if (b == (c2_node *)0x0) {
      return 1;
    }
    uVar5 = b->op;
    if (a->op == uVar5) break;
    if (a->op == 0x15f) {
      pcVar16 = *(c2_node **)&a[1].kind;
      iVar10 = types_compatible(a->type,pcVar16->type);
      pcVar15 = b;
      if (iVar10 == 0) goto LAB_1077ef1c;
    }
    else {
LAB_1077ef1c:
      if (uVar5 != 0x15f) {
LAB_1077ef64:
        return (-(uint)(a->op < b->op) & 0xfffffffe) + 1;
      }
      pcVar15 = *(c2_node **)&b[1].kind;
      iVar10 = types_compatible(b->type,pcVar15->type);
      pcVar16 = a;
      if (iVar10 == 0) goto LAB_1077ef64;
    }
    b = pcVar15;
    a = pcVar16;
    if (pcVar16 == pcVar15) {
      return 0;
    }
  }
  if (((a->kind != '\x11') && (uVar3 = b->type, a->type != uVar3)) &&
     ((iVar10 = tree_op_is_compare_like(a), iVar10 != 0 ||
      (iVar10 = types_compatible(a->type,uVar3), iVar10 == 0)))) {
    return (-(uint)(a->type < uVar3) & 0xfffffffe) + 1;
  }
  if (((a->op == 0x15f) &&
      (uVar3 = *(ushort *)(*(int *)&a[1].kind + 10), (uVar3 & 0xfff) < (a->type & 0xfff))) &&
     (uVar4 = *(ushort *)(*(int *)&b[1].kind + 10), uVar3 != uVar4)) {
    return (-(uint)(uVar3 < uVar4) & 0xfffffffe) + 1;
  }
  pcVar7 = (c2_operand *)b[1].rank_or_prev;
  for (pcVar6 = (c2_operand *)a[1].rank_or_prev; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next)
  {
    if (pcVar7 == (c2_operand *)0x0) {
      if (pcVar6 != (c2_operand *)0x0) {
        return 1;
      }
      goto LAB_1077f0c4;
    }
    if (((((1 << (pcVar6->kind & 0x1f) & 6U) == 0) || (pcVar6->sym->def == (c2_tuple *)0x0)) ||
        ((1 << (pcVar7->kind & 0x1f) & 6U) == 0)) || (pcVar7->sym->def == (c2_tuple *)0x0)) {
      iVar10 = merge_tails_operand_compare(pcVar6,pcVar7,0);
      if (iVar10 != 0) {
        return iVar10;
      }
    }
    else {
      if (pcVar6->kind != pcVar7->kind) {
        return (-(uint)(pcVar6->kind < pcVar7->kind) & 0xfffffffe) + 1;
      }
      iVar10 = types_compatible(pcVar6->type,pcVar7->type);
      if (iVar10 == 0) {
        return (-(uint)(pcVar6->type < pcVar7->type) & 0xfffffffe) + 1;
      }
    }
    pcVar7 = pcVar7->next;
  }
  if (pcVar7 != (c2_operand *)0x0) {
    return -1;
  }
LAB_1077f0c4:
  pcVar6 = *(c2_operand **)&a[1].kind;
  pcVar7 = *(c2_operand **)&b[1].kind;
  do {
    if (pcVar6 == (c2_operand *)0x0) {
      if (pcVar7 != (c2_operand *)0x0) {
        return -1;
      }
LAB_1077f315:
      switch(a->kind) {
      case '\x10':
        if (*(byte *)&a[2].next != *(byte *)&b[2].next) {
          return (-(uint)(*(byte *)&a[2].next < *(byte *)&b[2].next) & 0xfffffffe) + 1;
        }
        break;
      case '\x11':
        bVar1 = (byte)a->type;
        bVar2 = (byte)b->type;
        if (bVar1 != bVar2) {
          return (-(uint)(bVar1 < bVar2) & 0xfffffffe) + 1;
        }
        break;
      case '\x12':
        if (*(ushort *)&a[2].next != *(ushort *)&b[2].next) {
          return (-(uint)(*(ushort *)&a[2].next < *(ushort *)&b[2].next) & 0xfffffffe) + 1;
        }
      }
      return 0;
    }
    if (pcVar7 == (c2_operand *)0x0) {
      if (pcVar6 != (c2_operand *)0x0) {
        return 1;
      }
      goto LAB_1077f315;
    }
    bVar1 = pcVar6->kind;
    uVar13 = 1 << (bVar1 & 0x1f);
    pcVar12 = pcVar6;
    pcVar14 = pcVar7;
    if ((uVar13 & 0xffe) == 0) {
LAB_1077f153:
      iVar10 = merge_tails_tree_compare((c2_node *)pcVar12,(c2_node *)pcVar14);
LAB_1077f2c2:
      if (iVar10 != 0) {
        return iVar10;
      }
    }
    else {
      uVar11 = 1 << (pcVar7->kind & 0x1f);
      if ((uVar11 & 0xffe) == 0) goto LAB_1077f153;
      if (bVar1 != pcVar7->kind) {
        return (-(uint)(pcVar6->kind < pcVar7->kind) & 0xfffffffe) + 1;
      }
      if ((((uVar13 & 6) != 0) && (pcVar6->sym->def != (c2_tuple *)0x0)) &&
         (((uVar11 & 6) != 0 && (pcVar7->sym->def != (c2_tuple *)0x0)))) {
        iVar10 = merge_tails_operand_compare(pcVar6,pcVar7,1);
        if (iVar10 != 0) {
          return iVar10;
        }
        pcVar12 = (c2_operand *)pcVar6->sym->def;
        pcVar14 = (c2_operand *)pcVar7->sym->def;
        goto LAB_1077f153;
      }
      if (((((bVar1 != 6) ||
            ((pcVar12 = pcVar6->base, pcVar12 != (c2_operand *)0x0 &&
             (((1 << (pcVar12->kind & 0x1f) & 6U) == 0 || (pcVar12->sym->def == (c2_tuple *)0x0)))))
            ) || ((pcVar14 = pcVar6->index, pcVar14 != (c2_operand *)0x0 &&
                  (((1 << (pcVar14->kind & 0x1f) & 6U) == 0 ||
                   (pcVar14->sym->def == (c2_tuple *)0x0)))))) ||
          ((pcVar7->kind != '\x06' ||
           ((pcVar8 = pcVar7->base, pcVar8 != (c2_operand *)0x0 &&
            (((1 << (pcVar8->kind & 0x1f) & 6U) == 0 || (pcVar8->sym->def == (c2_tuple *)0x0))))))))
         || ((pcVar9 = pcVar7->index, pcVar9 != (c2_operand *)0x0 &&
             (((1 << (pcVar9->kind & 0x1f) & 6U) == 0 || (pcVar9->sym->def == (c2_tuple *)0x0))))))
      {
        iVar10 = merge_tails_operand_compare(pcVar6,pcVar7,1);
        goto LAB_1077f2c2;
      }
      if (pcVar12 == (c2_operand *)0x0) {
LAB_1077f25f:
        if (pcVar8 != (c2_operand *)0x0) {
LAB_1077f263:
          return (-(uint)(pcVar6->base != (c2_operand *)0x0) & 2) - 1;
        }
      }
      else {
        if (pcVar8 == (c2_operand *)0x0) {
          if (pcVar12 != (c2_operand *)0x0) goto LAB_1077f263;
          goto LAB_1077f25f;
        }
        iVar10 = merge_tails_tree_compare((c2_node *)pcVar12->sym->def,(c2_node *)pcVar8->sym->def);
        if (iVar10 != 0) {
          return iVar10;
        }
      }
      if (pcVar14 != (c2_operand *)0x0) {
        if (pcVar9 != (c2_operand *)0x0) {
          pcVar12 = (c2_operand *)pcVar14->sym->def;
          pcVar14 = (c2_operand *)pcVar9->sym->def;
          goto LAB_1077f153;
        }
        if (pcVar14 != (c2_operand *)0x0) goto LAB_1077f2e9;
      }
      if (pcVar9 != (c2_operand *)0x0) {
LAB_1077f2e9:
        return (-(uint)(pcVar6->index != (c2_operand *)0x0) & 2) - 1;
      }
    }
    pcVar6 = pcVar6->next;
    pcVar7 = pcVar7->next;
  } while( true );
}

