uint32_t __fastcall cxx_eh_object_needs_state(c2_tuple *t,void *obj)

{
  if (((t->op == 0x1a1) && (*(uint *)((int)obj + 0x2c) < 2)) &&
     ((*(uint *)((int)obj + 0x10) & 0x800) != 0)) {
    *(uint *)((int)obj + 0x10) = *(uint *)((int)obj + 0x10) & 0xfffffbff;
  }
  return *(uint *)((int)obj + 0x10) >> 10 & 1;
}

