c1_u8 __cdecl
class_vbase_get_info
          (c1_symbol *base,c1_symbol *cls,int *vbptr_offset,int *vbase_index,c1_type **base_type)

{
  c1_vbase_record *rec;
  
  rec = class_find_base_record(base,((cls->detail).cls)->vbases);
  if (rec != (c1_vbase_record *)0x0) {
    if (vbptr_offset != (int *)0x0) {
      *vbptr_offset = rec->vbptr_offset;
    }
    if (vbase_index != (int *)0x0) {
      *vbase_index = rec->vbase_index;
    }
    if (base_type != (c1_type **)0x0) {
      *base_type = rec->member->type;
    }
    return '\x01';
  }
  return '\0';
}

