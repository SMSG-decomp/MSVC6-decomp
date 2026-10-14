c2_operand * __fastcall
materialize_value_in_preheader(uint16_t type,c2_operand *op,c2_tuple *anchor,int allow_live_out)

{
  c2_cse_expr *pcVar1;
  c2_live_range *pcVar2;
  uint32_t op_00;
  uint uVar3;
  c2_operand *src;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_symbol *pcVar6;
  int iVar7;
  c2_tuple *pcVar8;
  uint uVar9;
  uint16_t uVar10;
  uint32_t local_8;
  
  if (op != (c2_operand *)0x0) {
    uVar3 = 1 << (op->kind & 0x1f);
    uVar9 = uVar3 & 6;
    if ((uVar9 == 0) || (pcVar1 = (op->sym->u18).expr, pcVar1 == (c2_cse_expr *)0x0)) {
      if ((uVar3 & 0x60) == 0) {
        if (uVar9 == 0) {
          if (((op->kind == 7) && (type != op->type)) &&
             (iVar7 = types_compatible(type,op->type), iVar7 != 0)) {
            operand_retype_keep_sets(op,type);
          }
        }
        else if ((type != op->type) && (iVar7 = types_compatible(type,op->type), iVar7 != 0)) {
          pcVar5 = (c2_operand *)node_clone((c2_node *)op);
          pcVar6 = symbol_get_part_2(pcVar5->sym,type,0,0);
          pcVar5->sym = pcVar6;
          pcVar5->type = type;
          return pcVar5;
        }
      }
      else {
        uVar4 = op->tag;
        pcVar2 = ((op->u18).range)->queue_prev;
        op_00._0_1_ = pcVar2->kind;
        op_00._1_1_ = pcVar2->flags5;
        op_00._2_1_ = pcVar2->flags6;
        op_00._3_1_ = pcVar2->flags7;
        pcVar5 = (c2_operand *)pcVar2->priority;
        iVar7 = types_compatible(type,*(uint16_t *)&pcVar2->self);
        uVar10 = type;
        if (iVar7 == 0) {
          uVar10 = *(uint16_t *)&pcVar2->self;
        }
        pcVar5 = materialize_value_in_preheader(pcVar5->type,pcVar5,anchor,allow_live_out);
        op = operand_new_mem(op_00,uVar10,(c2_symbol *)0x0,0,pcVar5,(c2_operand *)0x0,uVar4);
        if (uVar10 != type) {
          pcVar8 = tuple_new_unary_temp(op_00,type,op,tuple_insert_before,anchor);
          return pcVar8->dst;
        }
      }
    }
    else {
      local_8 = pcVar1->op;
      switch(local_8) {
      case 0x165:
      case 399:
      case 400:
        break;
      default:
        if (((allow_live_out != 0) || (uVar4 = operand_live_out_of_preheader(op), uVar4 == 0)) ||
           (((op->sym->u30).sizeopt.width_facts & 2) != 0)) {
          for (pcVar5 = pcVar1->operands; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
            if (((1 << (pcVar5->kind & 0x1f) & 6U) != 0) && (pcVar5->sym->def != (c2_tuple *)0x0)) {
              return op;
            }
          }
          goto LAB_10762ec7;
        }
        break;
      case 0x179:
      case 0x17a:
      case 0x17b:
      case 0x17c:
        local_8 = map_iv_update_opcode(local_8);
LAB_10762ec7:
        iVar7 = types_compatible(type,pcVar1->type);
        if ((iVar7 == 0) ||
           (((uVar10 = type, (1 << (byte)(type >> 0xc) & 0xeU) != 0 &&
             (iVar7 = op_is_compare_like(local_8), iVar7 != 0)) &&
            (((type & 0xf000) == 0x1000) != ((pcVar1->type & 0xf000) == 0x1000))))) {
          uVar10 = pcVar1->type;
        }
        pcVar5 = pcVar1->operands->next;
        src = materialize_value_in_preheader(uVar10,pcVar1->operands,anchor,allow_live_out);
        pcVar5 = materialize_value_in_preheader(uVar10,pcVar5,anchor,allow_live_out);
        if (pcVar5 == (c2_operand *)0x0) {
          pcVar8 = tuple_new_unary_temp(local_8,uVar10,src,tuple_insert_before,anchor);
        }
        else {
          pcVar8 = tuple_new_binary_temp(local_8,uVar10,src,pcVar5,tuple_insert_before,anchor);
        }
        if (uVar10 != type) {
          pcVar8 = tuple_new_unary_temp(0x15f,type,pcVar8->dst,tuple_insert_before,anchor);
        }
        return pcVar8->dst;
      }
    }
  }
  return op;
}

