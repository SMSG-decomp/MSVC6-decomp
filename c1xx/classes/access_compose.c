char __cdecl access_compose(byte path,byte member)

{
  return g_access_compose_table[(uint)path * 4 + (uint)member];
}

