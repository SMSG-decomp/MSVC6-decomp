fe_vector * __cdecl vector_grow(fe_vector *v)

{
  ushort uVar1;
  void **ppvVar2;
  short sVar3;
  fe_arena *a;
  uint uVar4;
  int iVar5;
  void **ppvVar6;
  void **ppvVar7;
  
  ppvVar6 = v->data;
  if (v->capacity < 1000) {
    sVar3 = v->capacity + 4;
  }
  else {
    sVar3 = 1000;
  }
  v->capacity = v->capacity + sVar3;
  uVar1 = v->capacity;
  a = g_arenas + v->arena;
  ppvVar7 = (void **)a->cur;
  ppvVar2 = (void **)g_arenas[v->arena].end;
  a->cur = (uchar *)(ppvVar7 + uVar1);
  if (ppvVar2 < ppvVar7 + uVar1) {
    arena_grow(a);
  }
  v->data = ppvVar7;
  if (v->count != 0) {
    for (uVar4 = (uint)v->count; uVar4 != 0; uVar4 = uVar4 - 1) {
      *ppvVar7 = *ppvVar6;
      ppvVar6 = ppvVar6 + 1;
      ppvVar7 = ppvVar7 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(uchar *)ppvVar7 = *(uchar *)ppvVar6;
      ppvVar6 = (void **)((int)ppvVar6 + 1);
      ppvVar7 = (void **)((int)ppvVar7 + 1);
    }
  }
  return v;
}

