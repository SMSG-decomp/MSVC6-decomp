uint32_t __fastcall try_negate_in_place(c2_node *n,c2_tuple *parent,int level)

{
  ushort uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint32_t uVar5;
  int iVar6;
  c2_tuple *t;
  c2_const_operand *op;
  c2_operand *parent_00;
  c2_fe_symbol *pcVar7;
  uint64_t uVar8;
  
  uVar4 = n->op - 0x146;
  if (0x2f < uVar4) {
    return 0;
  }
  do {
    parent_00 = (c2_operand *)n;
    switch((&switchD_1070b006::switchdataD_1070b29c)[uVar4]) {
    case 0x146:
      if (((level < 3) && ((level < 2 || ((parent_00->type & 0xf000) != 0x1000)))) &&
         ((level < 1 ||
          (uVar3._0_4_ = parent_00->u18, uVar3._4_4_ = parent_00->tag,
          uVar8 = const_normalize(parent_00->type,-(parent_00->u18).lo,
                                  -(parent_00->tag + (uint)((parent_00->u18).lo != 0))),
          uVar3 <= uVar8)))) {
        if (level < 0) {
          return 0;
        }
        if ((parent_00->type & 0xf000) != 0x2000) {
          return 0;
        }
        uVar2._0_4_ = parent_00->u18;
        uVar2._4_4_ = parent_00->tag;
        uVar8 = const_normalize(parent_00->type,-(parent_00->u18).lo,
                                -(parent_00->tag + (uint)((parent_00->u18).lo != 0)));
        if (uVar2 <= uVar8) {
          return 0;
        }
      }
      uVar8 = const_normalize(parent_00->type,-(parent_00->u18).lo,
                              -(parent_00->tag + (uint)((parent_00->u18).lo != 0)));
      parent_00->u18 = (c2_operand_u18)(int)uVar8;
      parent_00->tag = (int)(uVar8 >> 0x20);
      g_simplify_changed = 1;
      return 1;
    default:
      return 0;
    case 0x148:
      if ((level < 1) &&
         (iVar6 = float_const_compare_mask(4,(c2_float_const *)parent_00->sym,&g_ld_const_zero),
         iVar6 == 0)) {
        return 0;
      }
      t = negate_operand((c2_node *)parent_00,parent);
      fold_constant_operands(t,parent);
      g_simplify_changed = 1;
      return 1;
    case 0x15f:
      uVar1 = parent_00->type;
      if (((1 << (byte)(uVar1 >> 0xc) & 0xeU) != 0) &&
         (((*(c2_operand **)&parent_00->u18)->type & 0xfff) < (uVar1 & 0xfff))) {
        return 0;
      }
      if (((uVar1 & 0xf000) == 0x4000) && ((((parent_00->u18).children)->type & 0xf000) == 0x2000))
      {
        return 0;
      }
switchD_1070b006_caseD_171:
      uVar4 = (*(c2_operand **)&parent_00->u18)->op - 0x146;
      n = (c2_node *)*(c2_operand **)&parent_00->u18;
      parent = (c2_tuple *)parent_00;
      if (0x2f < uVar4) {
        return 0;
      }
      break;
    case 0x160:
      if (level != 3) {
        return 0;
      }
      parent_00->op = 0x16d;
      op = operand_new_intconst(parent_00->type,1,0);
      tuple_append_src((c2_tuple *)parent_00,op);
      g_simplify_changed = 1;
      return 1;
    case 0x161:
      tuple_forward_src_and_free((c2_tuple *)parent_00,parent);
      g_simplify_changed = 1;
      return 1;
    case 0x16e:
      uVar5 = try_negate_in_place((c2_node *)(parent_00->u18).reg,(c2_tuple *)parent_00,level);
      if (uVar5 == 0) {
        return 0;
      }
      parent_00->op = 0x16d;
      g_simplify_changed = 1;
      return 1;
    case 0x171:
      goto switchD_1070b006_caseD_171;
    case 0x175:
      if ((parent_00->type & 0xf000) == 0x2000) {
        return 0;
      }
    case 0x16f:
      for (pcVar7 = (c2_fe_symbol *)(parent_00->u18).reg; pcVar7 != (c2_fe_symbol *)0x0;
          pcVar7 = pcVar7->next) {
        uVar5 = try_negate_in_place((c2_node *)pcVar7,(c2_tuple *)parent_00,0);
        if (uVar5 != 0) {
          return 1;
        }
      }
      if (0 < level) {
        for (pcVar7 = (c2_fe_symbol *)(parent_00->u18).reg; pcVar7 != (c2_fe_symbol *)0x0;
            pcVar7 = pcVar7->next) {
          uVar5 = try_negate_in_place((c2_node *)pcVar7,(c2_tuple *)parent_00,1);
          if (uVar5 != 0) {
            return 1;
          }
        }
        if (1 < level) {
          for (pcVar7 = (c2_fe_symbol *)(parent_00->u18).reg; pcVar7 != (c2_fe_symbol *)0x0;
              pcVar7 = pcVar7->next) {
            uVar5 = try_negate_in_place((c2_node *)pcVar7,(c2_tuple *)parent_00,2);
            if (uVar5 != 0) {
              return 1;
            }
          }
          if ((2 < level) &&
             (pcVar7 = (c2_fe_symbol *)(parent_00->u18).reg, pcVar7 != (c2_fe_symbol *)0x0)) {
            do {
              uVar5 = try_negate_in_place((c2_node *)pcVar7,(c2_tuple *)parent_00,3);
              if (uVar5 != 0) {
                return 1;
              }
              pcVar7 = pcVar7->next;
            } while (pcVar7 != (c2_fe_symbol *)0x0);
            return 0;
          }
        }
      }
      return 0;
    }
  } while( true );
}

