void __thiscall line_map_set_cached_row(c1_lex_position_record *position_record,void *file)

{
  int iVar1;
  uint uVar2;
  fe_line_map_row *pfVar3;
  
  iVar1 = position_record->position;
  (position_record->cached_row).position = iVar1;
  (position_record->cached_row).file = file;
  uVar2 = (position_record->map).count;
  pfVar3 = (position_record->map).rows;
  (position_record->cached_row).line = (pfVar3[uVar2 - 1].line - pfVar3[uVar2 - 1].position) + iVar1
  ;
  return;
}

