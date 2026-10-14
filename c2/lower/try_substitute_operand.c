int __fastcall
try_substitute_operand(c2_tuple *t,c2_operand *op,c2_operand *new_op,c2_replace_fn *replace_fn)

{
  ushort op_type;
  ushort new_type;
  c2_operand *pcVar1;
  int iVar2;
  int part_offset;
  uint uVar3;
  c2_tuple *pcVar4;
  
  op_type = op->type;
  uVar3 = (uint)op_type;
  new_type = new_op->type;
  pcVar4 = t;
  if (op_type != new_type) {
    part_offset = 0;
    if (op->kind == '\x01') {
      part_offset = op->sym->offset;
      part_offset = (3 < part_offset) - 1 & part_offset;
    }
    switch(new_op->kind) {
    case '\x01':
      if ((1 << (new_op->kind & 0x1f) & 6U) != 0) {
        pcVar4 = new_op->sym->def;
        if (((pcVar4 != (c2_tuple *)0x0) &&
            (pcVar1 = find_dst_symbol_ref(pcVar4,new_op->sym),
            (int)(uVar3 & 0xfff) <= pcVar1->sym->offset)) &&
           (new_op = pcVar1, ((pcVar1->type ^ op_type) & 0xfff) != 0)) {
          return 0;
        }
      }
      iVar2 = substitution_allowed((new_op->u18).reg,uVar3 & 0xfff,0);
      pcVar4 = t;
      if (iVar2 == 0) {
        return 0;
      }
      break;
    case '\x02':
      if (t->op != 0x14a) {
        iVar2 = try_substitute_operand_case_6(new_type,op_type,op,new_op,part_offset,t,replace_fn);
        return iVar2;
      }
      break;
    case '\x03':
    case '\x04':
      if (0 < part_offset) {
        return 0;
      }
      if ((uVar3 & 0xfff) != 4) {
        return 0;
      }
      break;
    case '\x06':
      if ((new_type & 0xfff) < (uVar3 & 0xfff)) {
        uVar3 = new_type & 0xfff;
        iVar2 = test_narrowing_ok(t,uVar3);
        if (iVar2 == 0) {
          return 0;
        }
        set_op_width(t,uVar3);
        goto LAB_10713261;
      }
    }
    new_op = operand_narrow_to(new_op,op_type,part_offset);
  }
LAB_10713261:
  (*replace_fn)(pcVar4,op,new_op);
  return 1;
}

