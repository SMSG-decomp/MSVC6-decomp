c2_bitset * __fastcall split_uncolourable_live_range(c2_live_range *range,int reg_class)

{
  byte bVar1;
  c2_bitset *bs;
  c2_bitset *bs_00;
  int iVar2;
  c2_bitset *regs;
  
  bs = bitset_clone(g_class_allowed_sets[reg_class]);
  if (g_ebp_allocatable == 0) {
    bitset_clear(bs,6);
  }
  bVar1 = range->flags5;
  range->flags5 = bVar1 | 2;
  bs_00 = bitset_new(6);
  bitset_set(bs_00,range->id);
  regs = bs;
  if (((bVar1 & 0x80) != 0) && (regs = g_byte_register_set, range->sym->cls == '\r')) {
    materialize_byte_constant_uses(range);
    regs = g_byte_register_set;
  }
  place_split_points_for_range(range,regs);
  bitset_free(bs);
  if (g_colour_queue == (c2_live_range *)0x0) {
    g_colour_queue = range;
  }
  if (((range->flags5 & 8) == 0) && (iVar2 = is_rematerializable_def((range->u38).def), iVar2 != 0))
  {
    split_live_range_regions(range);
  }
  return bs_00;
}

