int __fastcall is_compare_branch_op(uint32_t op)

{
  if ((0x17d < op) && (op < 0x184)) {
    return 1;
  }
  return 0;
}

