void __thiscall
pch_page_table_fill(c1xx_pch_stream_reader **page_map,c1xx_pch_stream_reader *segment,uint base,
                   int size)

{
  uint uVar1;
  
  if (size != 0) {
    uVar1 = size + 0xffffU >> 0x10;
    do {
      uVar1 = uVar1 - 1;
      page_map[base >> 0x10] = segment;
      base = base + 0x10000;
    } while (uVar1 != 0);
  }
  return;
}

