void __fastcall reader_load_bitfield(c2_reader_cell *cell,uint16_t type,int a)

{
  cell->flags = cell->flags & 0xfb;
  reader_load_value(cell,type,0,a);
  reader_extract_bitfield(cell,type);
  return;
}

