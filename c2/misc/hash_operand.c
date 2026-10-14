uint32_t __fastcall hash_operand(c2_operand *op)

{
  c2_fe_symbol *pcVar1;
  uint uVar2;
  uint32_t uVar3;
  byte bVar4;
  int iVar5;
  uint32_t hash_value;
  longlong lVar6;
  c2_operand *child;
  c2_operand *def_tree;
  
  iVar5 = 0;
  bVar4 = op->kind;
  switch(*(undefined1 *)((int)hash_handler_jump_table + bVar4 + 0x1f)) {
  case 0:
    hash_value = 1 << (bVar4 & 0x1f) & 6;
    if ((hash_value != 0) && (def_tree = (c2_operand *)op->sym->def, def_tree != (c2_operand *)0x0))
    {
      uVar3 = hash_operand(def_tree);
      return uVar3 & 0xffff;
    }
    if ((hash_value != 0) && (op->sym->cls == '\x03')) {
      return (op->sym->id & 0x3ff) << 6;
    }
    uVar2 = op->sym->id;
    hash_value = uVar2 >> 0x10 ^ uVar2 & 0xffff;
    if (bVar4 != 3) {
      return (int)(hash_value << 5) >> 0x10 ^ (hash_value & 0x7ff) << 5;
    }
    break;
  case 1:
    hash_value = (op->sym->u28).frame_home;
    return hash_value >> 0x10 ^ hash_value & 0xffff;
  case 2:
    hash_value = ((op->disp >> 0x10 ^ op->disp & 0xffffU) - 0x145) + (uint)(ushort)op->op;
    if (op->base != (c2_operand *)0x0) {
      uVar3 = hash_operand(op->base);
      return hash_value + uVar3 * 0x100 & 0xffff;
    }
    break;
  case 3:
    lVar6 = allshr((op->u18).lo,op->tag,' ');
    hash_value = (uint)lVar6 ^ (op->u18).lo;
    return ((int)hash_value >> 0x10 ^ hash_value & 0xffff) & 0xffff;
  case 4:
    hash_value = *(uint32_t *)op->sym->offset;
    return ((int)hash_value >> 0x10 ^ hash_value & 0xffff) & 0xffff;
  case 5:
    pcVar1 = op->sym->fe;
    return ((int)pcVar1 >> 0x10 ^ (uint)pcVar1 & 0xffff) & 0xffff;
  case 6:
    hash_value = 0;
    break;
  case 7:
    bVar4 = 0;
    for (child = (op->u18).children; child != (c2_operand *)0x0; child = child->next) {
      iVar5 = iVar5 + ((child->rank & 0xffff) << bVar4);
      bVar4 = bVar4 + 1 & 7;
    }
    return iVar5 + (uint)(ushort)((short)op->op - 0x145) & 0xffff;
  }
  return hash_value & 0xffff;
}

