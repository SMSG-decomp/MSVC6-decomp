void __thiscall pch_page_table_fill(c1_pch_segment **table,c1_pch_segment *value,uint base,int size)

{
  uint uVar1;
  
  if (size != 0) {
    uVar1 = size + 0xffffU >> 0x10;
    do {
      uVar1 = uVar1 - 1;
      table[base >> 0x10] = value;
      base = base + 0x10000;
    } while (uVar1 != 0);
  }
  return;
}

