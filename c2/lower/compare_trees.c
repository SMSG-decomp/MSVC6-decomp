int __fastcall compare_trees(c2_node *a,c2_node *b)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  int iVar8;
  uint uVar9;
  c2_node *a_sub;
  uint uVar10;
  c2_operand *pcVar11;
  c2_node *next_b;
  c2_node *next_a;
  c2_operand *src_index;
  c2_operand *a_src;
  c2_operand *a_index;
  c2_operand *b_index;
  uint32_t b_op;
  
  if (a == b) {
    return 0;
  }
  while( true ) {
    if ((c2_operand *)a == (c2_operand *)0x0) {
      return -1;
    }
    if ((c2_operand *)b == (c2_operand *)0x0) {
      return 1;
    }
    b_op = ((c2_operand *)b)->op;
    if (((c2_operand *)a)->op == b_op) break;
    if (((c2_operand *)a)->op == 0x15f) {
      next_a = (c2_node *)(((c2_operand *)a)->u18).children;
      iVar8 = types_compatible(((c2_operand *)a)->type,((c2_operand *)next_a)->type);
      next_b = b;
      if (iVar8 == 0) goto LAB_1070a2b6;
    }
    else {
LAB_1070a2b6:
      if (b_op != 0x15f) {
LAB_1070a2be:
        return (-(uint)(((c2_operand *)a)->op < ((c2_operand *)b)->op) & 0xfffffffe) + 1;
      }
      next_b = (c2_node *)(((c2_operand *)b)->u18).children;
      iVar8 = types_compatible(((c2_operand *)b)->type,((c2_operand *)next_b)->type);
      next_a = a;
      if (iVar8 == 0) goto LAB_1070a2be;
    }
LAB_1070a309:
    b = next_b;
    a = next_a;
    if (next_a == next_b) {
      return 0;
    }
  }
  if ((1 << (((c2_operand *)a)->kind & 0x1f) & 0xffeU) != 0) {
    if ((1 << (((c2_operand *)b)->kind & 0x1f) & 0xffeU) == 0) {
      return -1;
    }
    iVar8 = operand_compare((c2_operand *)a,(c2_operand *)b);
    if (iVar8 == 0) {
      return 0;
    }
    if ((((1 << (((c2_operand *)a)->kind & 0x1f) & 6U) != 0) &&
        (next_a = (c2_node *)((c2_operand *)a)->sym->def, (c2_tuple *)next_a != (c2_tuple *)0x0)) &&
       (((1 << (((c2_operand *)b)->kind & 0x1f) & 6U) != 0 &&
        (next_b = (c2_node *)((c2_operand *)b)->sym->def, (c2_tuple *)next_b != (c2_tuple *)0x0))))
    goto LAB_1070a309;
    if (((c2_operand *)a)->kind != '\x06') {
      return iVar8;
    }
    pcVar5 = ((c2_operand *)a)->base;
    if (pcVar5 != (c2_operand *)0x0) {
      if ((1 << (pcVar5->kind & 0x1f) & 6U) == 0) {
        return iVar8;
      }
      if (pcVar5->sym->def == (c2_tuple *)0x0) {
        return iVar8;
      }
    }
    a_index = ((c2_operand *)a)->index;
    if (a_index != (c2_operand *)0x0) {
      if ((1 << (a_index->kind & 0x1f) & 6U) == 0) {
        return iVar8;
      }
      if (a_index->sym->def == (c2_tuple *)0x0) {
        return iVar8;
      }
    }
    if (((c2_operand *)b)->kind != '\x06') {
      return iVar8;
    }
    pcVar11 = ((c2_operand *)b)->base;
    if ((pcVar11 != (c2_operand *)0x0) &&
       (((1 << (pcVar11->kind & 0x1f) & 6U) == 0 || (pcVar11->sym->def == (c2_tuple *)0x0)))) {
      return iVar8;
    }
    b_index = ((c2_operand *)b)->index;
    if (b_index != (c2_operand *)0x0) {
      if ((1 << (b_index->kind & 0x1f) & 6U) == 0) {
        return iVar8;
      }
      if (b_index->sym->def == (c2_tuple *)0x0) {
        return iVar8;
      }
    }
    if (pcVar5 == (c2_operand *)0x0) {
LAB_1077ec73:
      if (pcVar11 != (c2_operand *)0x0) {
LAB_1077ec7b:
        return (-(uint)(pcVar5 != (c2_operand *)0x0) & 2) - 1;
      }
    }
    else {
      if (pcVar11 == (c2_operand *)0x0) {
        if (pcVar5 != (c2_operand *)0x0) goto LAB_1077ec7b;
        goto LAB_1077ec73;
      }
      iVar8 = compare_trees((c2_node *)pcVar5->sym->def,(c2_node *)pcVar11->sym->def);
      if (iVar8 != 0) {
        return iVar8;
      }
    }
    if (a_index != (c2_operand *)0x0) {
      if (b_index != (c2_operand *)0x0) {
        iVar8 = compare_trees((c2_node *)a_index->sym->def,(c2_node *)b_index->sym->def);
        return iVar8;
      }
      if (a_index != (c2_operand *)0x0) goto LAB_1077eca6;
    }
    if (b_index == (c2_operand *)0x0) {
      return 0;
    }
LAB_1077eca6:
    return (-(uint)(a_index != (c2_operand *)0x0) & 2) - 1;
  }
  if ((1 << (((c2_operand *)b)->kind & 0x1f) & 0xffeU) != 0) {
    return 1;
  }
  uVar3 = ((c2_operand *)a)->type;
  uVar4 = ((c2_operand *)b)->type;
  if (uVar3 != uVar4) {
    iVar8 = tree_op_is_compare_like(a);
    if (iVar8 != 0) {
LAB_1070a5f6:
      return (-(uint)(((c2_operand *)a)->type < uVar4) & 0xfffffffe) + 1;
    }
    uVar3 = ((c2_operand *)a)->type;
    iVar8 = types_compatible(uVar3,uVar4);
    if (iVar8 == 0) goto LAB_1070a5f6;
  }
  if (((((c2_operand *)a)->op == 0x15f) &&
      (uVar4 = ((((c2_operand *)a)->u18).children)->type, (uVar4 & 0xfff) < (uVar3 & 0xfff))) &&
     (uVar3 = ((((c2_operand *)b)->u18).children)->type, uVar4 != uVar3)) {
    return (-(uint)(uVar4 < uVar3) & 0xfffffffe) + 1;
  }
  pcVar11 = (c2_operand *)((c2_operand *)b)->tag;
  for (pcVar5 = (c2_operand *)((c2_operand *)a)->tag; pcVar5 != (c2_operand *)0x0;
      pcVar5 = pcVar5->next) {
    if (pcVar11 == (c2_operand *)0x0) {
      if (pcVar5 != (c2_operand *)0x0) {
        return 1;
      }
      goto LAB_1070a50c;
    }
    if (((((1 << (pcVar5->kind & 0x1f) & 6U) == 0) || (pcVar5->sym->def == (c2_tuple *)0x0)) ||
        ((1 << (pcVar11->kind & 0x1f) & 6U) == 0)) || (pcVar11->sym->def == (c2_tuple *)0x0)) {
      iVar8 = operand_compare(pcVar5,pcVar11);
      if (iVar8 != 0) {
        return iVar8;
      }
    }
    else {
      if (pcVar5->kind != pcVar11->kind) {
        return (-(uint)(pcVar5->kind < pcVar11->kind) & 0xfffffffe) + 1;
      }
      iVar8 = types_compatible(pcVar5->type,pcVar11->type);
      if (iVar8 == 0) {
        return (-(uint)(pcVar5->type < pcVar11->type) & 0xfffffffe) + 1;
      }
    }
    pcVar11 = pcVar11->next;
  }
  if (pcVar11 != (c2_operand *)0x0) {
    return -1;
  }
LAB_1070a50c:
  a_src = (((c2_operand *)a)->u18).children;
  pcVar5 = (((c2_operand *)b)->u18).children;
  do {
    if (a_src == (c2_operand *)0x0) {
      if (pcVar5 != (c2_operand *)0x0) {
        return -1;
      }
LAB_1070a5be:
      switch(((c2_operand *)a)->kind) {
      case '\x10':
        if (*(byte *)&((c2_operand *)a)->base_sym != *(byte *)&((c2_operand *)b)->base_sym) {
          return (-(uint)(*(byte *)&((c2_operand *)a)->base_sym <
                         *(byte *)&((c2_operand *)b)->base_sym) & 0xfffffffe) + 1;
        }
        break;
      case '\x11':
        bVar1 = (byte)((c2_operand *)a)->type;
        bVar2 = (byte)((c2_operand *)b)->type;
        if (bVar1 != bVar2) {
          return (-(uint)(bVar1 < bVar2) & 0xfffffffe) + 1;
        }
        break;
      case '\x12':
        if (*(ushort *)&((c2_operand *)a)->base_sym != *(ushort *)&((c2_operand *)b)->base_sym) {
          return (-(uint)(*(ushort *)&((c2_operand *)a)->base_sym <
                         *(ushort *)&((c2_operand *)b)->base_sym) & 0xfffffffe) + 1;
        }
      }
      return 0;
    }
    if (pcVar5 == (c2_operand *)0x0) {
      if (a_src != (c2_operand *)0x0) {
        return 1;
      }
      goto LAB_1070a5be;
    }
    bVar1 = a_src->kind;
    uVar10 = 1 << (bVar1 & 0x1f);
    a_sub = (c2_node *)a_src;
    pcVar11 = pcVar5;
    if ((uVar10 & 0xffe) == 0) {
LAB_1070a790:
      iVar8 = compare_trees(a_sub,(c2_node *)pcVar11);
LAB_1070a586:
      if (iVar8 != 0) {
        return iVar8;
      }
    }
    else {
      uVar9 = 1 << (pcVar5->kind & 0x1f);
      if ((uVar9 & 0xffe) == 0) goto LAB_1070a790;
      if (bVar1 != pcVar5->kind) {
        return (-(uint)(a_src->kind < pcVar5->kind) & 0xfffffffe) + 1;
      }
      if ((((uVar10 & 6) != 0) &&
          (a_sub = (c2_node *)a_src->sym->def, (c2_tuple *)a_sub != (c2_tuple *)0x0)) &&
         (((uVar9 & 6) != 0 &&
          (pcVar11 = (c2_operand *)pcVar5->sym->def, pcVar11 != (c2_operand *)0x0))))
      goto LAB_1070a790;
      if (((((bVar1 != 6) ||
            ((pcVar11 = a_src->base, pcVar11 != (c2_operand *)0x0 &&
             (((1 << (pcVar11->kind & 0x1f) & 6U) == 0 || (pcVar11->sym->def == (c2_tuple *)0x0)))))
            ) || ((src_index = a_src->index, src_index != (c2_operand *)0x0 &&
                  (((1 << (src_index->kind & 0x1f) & 6U) == 0 ||
                   (src_index->sym->def == (c2_tuple *)0x0)))))) ||
          ((pcVar5->kind != '\x06' ||
           ((pcVar6 = pcVar5->base, pcVar6 != (c2_operand *)0x0 &&
            (((1 << (pcVar6->kind & 0x1f) & 6U) == 0 || (pcVar6->sym->def == (c2_tuple *)0x0))))))))
         || ((pcVar7 = pcVar5->index, pcVar7 != (c2_operand *)0x0 &&
             (((1 << (pcVar7->kind & 0x1f) & 6U) == 0 || (pcVar7->sym->def == (c2_tuple *)0x0))))))
      {
        iVar8 = operand_compare(a_src,pcVar5);
        goto LAB_1070a586;
      }
      if (pcVar11 == (c2_operand *)0x0) {
LAB_1077ed6d:
        if (pcVar6 != (c2_operand *)0x0) {
LAB_1077ed75:
          return (-(uint)(a_src->base != (c2_operand *)0x0) & 2) - 1;
        }
      }
      else {
        if (pcVar6 == (c2_operand *)0x0) {
          if (pcVar11 != (c2_operand *)0x0) goto LAB_1077ed75;
          goto LAB_1077ed6d;
        }
        iVar8 = compare_trees((c2_node *)pcVar11->sym->def,(c2_node *)pcVar6->sym->def);
        if (iVar8 != 0) {
          return iVar8;
        }
      }
      if (src_index != (c2_operand *)0x0) {
        if (pcVar7 != (c2_operand *)0x0) {
          a_sub = (c2_node *)src_index->sym->def;
          pcVar11 = (c2_operand *)pcVar7->sym->def;
          goto LAB_1070a790;
        }
        if (src_index != (c2_operand *)0x0) goto LAB_1077edb0;
      }
      if (pcVar7 != (c2_operand *)0x0) {
LAB_1077edb0:
        return (-(uint)(a_src->index != (c2_operand *)0x0) & 2) - 1;
      }
    }
    a_src = a_src->next;
    pcVar5 = pcVar5->next;
  } while( true );
}

