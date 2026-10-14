void __thiscall array_swap(c1xx_pdb_array *array,c1xx_pdb_array *other)

{
  c1_u32 *pcVar1;
  c1_u32 cVar2;
  
  pcVar1 = array->data;
  array->data = other->data;
  other->data = pcVar1;
  cVar2 = array->count;
  array->count = other->count;
  other->count = cVar2;
  cVar2 = array->capacity;
  array->capacity = other->capacity;
  other->capacity = cVar2;
  return;
}

