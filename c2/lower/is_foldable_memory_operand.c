int __fastcall is_foldable_memory_operand(c2_operand *op)

{
  ushort uVar1;
  
  if ((((op->kind == '\x06') && (op->op != 0x152)) &&
      ((g_opt_dlp == 0 || (((uint)op->sym & 0x3ffff) == 0)))) &&
     ((uVar1 = op->type & 0xfff, uVar1 < 5 && (uVar1 != 3)))) {
    return 1;
  }
  return 0;
}

