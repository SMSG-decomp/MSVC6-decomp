int __fastcall expand_multi_op_pseudo(c2_tuple *t)

{
  uint16_t uVar1;
  ushort uVar2;
  c2_const_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_fe_symbol *label_sym;
  c2_tuple *pcVar6;
  uint32_t uVar7;
  c2_operand *pcVar8;
  c2_operand *dst;
  c2_operand *pcVar9;
  code *pcVar10;
  c2_insert_fn *insert_fn;
  int32_t selector;
  
  pcVar9 = t->src;
  selector = (pcVar9->u18).lo;
  if (selector < 0x183) {
    if (selector != 0x182) {
      if (selector < 0x60) {
        return 0;
      }
      if (0x61 < selector) {
        return 0;
      }
      uVar1 = t->type;
      pcVar4 = t->prev;
      pcVar10 = tuple_insert_before;
      pcVar6 = t;
      pcVar3 = operand_new_intconst(0x1004,0,0);
      pcVar9 = operand_new_hardreg(0x1f,uVar1);
      pcVar6 = tuple_new(0x81,uVar1,pcVar9,pcVar3,pcVar10,pcVar6);
      tuple_remove_src(pcVar6,pcVar6->src);
      if (((pcVar4->op == 0x60) && (pcVar9 = pcVar4->src, pcVar4->dst->type == pcVar9->type)) &&
         (pcVar9->kind != '\x01')) {
        pcVar10 = tuple_insert_before;
        pcVar6 = t;
        pcVar5 = operand_new_hardreg(0x1f,uVar1);
        pcVar8 = operand_new_hardreg(0x1f,uVar1);
        tuple_new_binary(0x46,uVar1,pcVar8,pcVar5,pcVar9,pcVar10,pcVar6);
        tuple_unlink_free(pcVar4);
      }
      else {
        pcVar10 = tuple_insert_before;
        pcVar4 = t;
        pcVar9 = operand_new_hardreg(0x1f,uVar1);
        pcVar5 = operand_new_hardreg(0x20,uVar1);
        pcVar8 = operand_new_hardreg(0x1f,uVar1);
        tuple_new_binary(0x4c,uVar1,pcVar8,pcVar5,pcVar9,pcVar10,pcVar4);
      }
      pcVar10 = tuple_insert_before;
      pcVar4 = t;
      pcVar9 = operand_new_hardreg(0x1f,uVar1);
      pcVar5 = operand_new_hardreg(0x1f,uVar1);
      tuple_new(0x60,uVar1,pcVar5,pcVar9,pcVar10,pcVar4);
      pcVar10 = tuple_insert_before;
      pcVar4 = t;
      pcVar9 = operand_new_hardreg(0x1f,uVar1);
      pcVar5 = operand_new_hardreg(0x1f,uVar1);
      tuple_new(0x89,uVar1,pcVar5,pcVar9,pcVar10,pcVar4);
      pcVar10 = tuple_insert_before;
      pcVar4 = t;
      pcVar9 = operand_new_hardreg(0x20,uVar1);
      pcVar5 = operand_new_hardreg(0x1f,uVar1);
      tuple_new(0x5f,uVar1,pcVar5,pcVar9,pcVar10,pcVar4);
      pcVar10 = tuple_insert_before;
      pcVar4 = t;
      pcVar9 = operand_new_hardreg(0x20,uVar1);
      pcVar5 = operand_new_hardreg(0x1f,uVar1);
      pcVar8 = operand_new_hardreg(0x1f,uVar1);
      tuple_new_binary(0x47,uVar1,pcVar8,pcVar5,pcVar9,pcVar10,pcVar4);
      pcVar10 = tuple_insert_before;
      pcVar4 = t;
      pcVar9 = operand_new_hardreg(0x1f,uVar1);
      pcVar5 = operand_new_hardreg(0x1f,uVar1);
      tuple_new(0x75,uVar1,pcVar5,pcVar9,pcVar10,pcVar4);
      pcVar10 = tuple_insert_before;
      pcVar4 = t;
      pcVar3 = operand_new_intconst(0x1004,0,0);
      pcVar9 = operand_new_hardreg(0x1f,uVar1);
      pcVar4 = tuple_new(0x94,uVar1,pcVar9,pcVar3,pcVar10,pcVar4);
      tuple_remove_src(pcVar4,pcVar4->src);
      pcVar10 = tuple_insert_before;
      pcVar4 = t;
      pcVar9 = operand_new_hardreg(0x1f,uVar1);
      pcVar5 = operand_new_hardreg(0x20,uVar1);
      pcVar8 = operand_new_hardreg(0x1f,uVar1);
      tuple_new_binary(0x4b,uVar1,pcVar8,pcVar5,pcVar9,pcVar10,pcVar4);
      pcVar10 = tuple_insert_before;
      pcVar4 = t;
      pcVar9 = operand_new_hardreg(0x1f,uVar1);
      pcVar5 = operand_new_hardreg(0x1f,uVar1);
      tuple_new(0x8a,uVar1,pcVar5,pcVar9,pcVar10,pcVar4);
      pcVar10 = tuple_insert_before;
      pcVar9 = operand_new_hardreg(0x1f,uVar1);
      pcVar5 = operand_new_hardreg(0x20,uVar1);
      tuple_new(99,uVar1,pcVar5,pcVar9,pcVar10,t);
      return 1;
    }
    uVar1 = t->type;
    pcVar5 = pcVar9->next->next;
    selector = (pcVar9->next->u18).lo;
    uVar2 = uVar1 & 0xfff;
    pcVar9 = pcVar5->next;
    if (((uVar2 == 1) && (selector != 0)) && ((uint)selector < 4)) {
      pcVar10 = tuple_insert_before;
      pcVar9 = operand_narrow_to(pcVar5,uVar1,1);
      tuple_new(1,uVar1,pcVar9,pcVar5,pcVar10,t);
      return 1;
    }
    pcVar8 = operand_narrow_to(pcVar5,0x1004,0);
    dst = operand_narrow_to(pcVar9,0x1004,0);
    pcVar4 = tuple_new(1,uVar1,pcVar9,pcVar5,tuple_insert_before,t);
    insert_fn = tuple_insert_after;
    if (uVar2 == 2) {
      pcVar3 = operand_new_intconst(0x1004,0x10,0);
      pcVar4 = tuple_new_binary(0x2a,0x1004,dst,dst,pcVar3,insert_fn,pcVar4);
      set_flags_effects(pcVar4);
      insert_fn = tuple_insert_before;
    }
    else {
      pcVar5 = pcVar9;
      pcVar9 = operand_narrow_to(pcVar9,uVar1,1);
      t = pcVar4;
    }
    pcVar4 = tuple_new(1,uVar1,pcVar9,pcVar5,insert_fn,t);
    pcVar4 = tuple_new(1,0x1004,pcVar8,dst,tuple_insert_after,pcVar4);
    if (uVar2 == 1) {
      insert_fn = tuple_insert_after;
      pcVar3 = operand_new_intconst(0x1004,0x10,0);
      pcVar4 = tuple_new_binary(0x2a,0x1004,pcVar8,pcVar8,pcVar3,insert_fn,pcVar4);
      set_flags_effects(pcVar4);
      pcVar9 = operand_narrow_to(pcVar8,0x1002,0);
      pcVar5 = operand_narrow_to(dst,0x1002,0);
      tuple_new(1,0x1002,pcVar9,pcVar5,tuple_insert_after,pcVar4);
      return 1;
    }
  }
  else {
    if (selector != 0x183) {
      return 0;
    }
    pcVar9 = pcVar9->next;
    uVar1 = t->type;
    insert_fn = tuple_insert_before;
    uVar7 = (pcVar9->next->u18).lo;
    pcVar4 = t;
    pcVar3 = operand_new_intconst(uVar1,uVar7 - 1 | 0x80000000,0);
    pcVar4 = tuple_new_binary(0x2e,uVar1,pcVar9,pcVar9,pcVar3,insert_fn,pcVar4);
    pcVar5 = tuple_add_flags_result(pcVar4);
    label_sym = label_symbol_new();
    pcVar6 = tuple_new_label(label_sym);
    tuple_new_branch(0xf,'\x0e',(c2_node *)pcVar6,pcVar5,pcVar4,tuple_insert_before,t);
    pcVar4 = tuple_new(0x1e,uVar1,pcVar9,pcVar9,tuple_insert_before,t);
    set_flags_effects(pcVar4);
    uVar7 = -uVar7;
    insert_fn = tuple_insert_before;
    pcVar4 = t;
    pcVar3 = operand_new_intconst(uVar1,uVar7,(int)uVar7 >> 0x1f);
    pcVar4 = tuple_new_binary(0x30,uVar1,pcVar9,pcVar9,pcVar3,insert_fn,pcVar4);
    set_flags_effects(pcVar4);
    pcVar4 = tuple_new(0x21,uVar1,pcVar9,pcVar9,tuple_insert_before,t);
    set_flags_effects(pcVar4);
    tuple_insert_after(pcVar4,pcVar6);
  }
  return 1;
}

