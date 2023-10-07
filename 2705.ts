// ? 2705. Compact Object
// ? https://leetcode.com/problems/compact-object/description/

type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

type MapFunc = (value: JSONValue, index: number) => Obj;

function compactObject(obj: Obj): Obj {
  if (typeof obj !== "object" || obj === null) {
    return obj;
  }

  if (Array.isArray(obj)) {
    return obj.filter(Boolean).map(compactObject as MapFunc);
  }

  const compact: Obj = {};

  for (const key in obj) {
    const value = compactObject(obj[key] as Obj);
    if (Boolean(value)) {
      compact[key] = value;
    }
  }

  return compact;
}
