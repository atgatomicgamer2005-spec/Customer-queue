<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Student Array Manager | C++ Array Demo</title>
<style>
*{box-sizing:border-box}
body{margin:0;font-family:Consolas,monospace;background:#020617;color:#e2e8f0;display:flex;justify-content:center;padding:15px}
.card{width:100%;max-width:550px;background:#0f172a;border:1px solid #1e293b;border-radius:20px;padding:22px;box-shadow:0 0 40px rgba(56,189,248,0.1)}
.header{text-align:center;border-bottom:1px solid #1e293b;padding-bottom:15px;margin-bottom:15px}
.header h2{margin:0;color:#22d3ee;letter-spacing:1px}
.header span{font-size:11px;color:#64748b;background:#1e293b;padding:4px 10px;border-radius:20px}
.inputs{display:grid;grid-template-columns:1fr 100px;gap:8px}
input{padding:13px;background:#020617;border:1px solid #334155;border-radius:10px;color:white;outline:none}
input:focus{border-color:#22d3ee}
.main-btn{width:100%;margin-top:10px;padding:14px;background:linear-gradient(90deg,#22d3ee,#0ea5e9);color:#000;border:none;border-radius:10px;font-weight:800;cursor:pointer;font-size:15px}
.controls{display:grid;grid-template-columns:1fr 1fr 1fr 1fr;gap:6px;margin-top:10px}
.controls button{padding:10px;border-radius:8px;border:1px solid #334155;background:#1e293b;color:#94a3b8;cursor:pointer;font-size:12px;font-weight:600}
.controls button:hover{background:#22d3ee;color:#000}
.array-box{margin-top:15px;background:#020617;border:1px dashed #334155;border-radius:12px;padding:12px;min-height:120px}
.item{display:flex;justify-content:space-between;align-items:center;background:#1e293b;margin:6px 0;padding:10px 12px;border-radius:8px;border-left:3px solid #22d3ee;animation:slide 0.3s}
@keyframes slide{from{transform:translateX(-10px);opacity:0}to{transform:translateX(0);opacity:1}}
.index{font-size:10px;color:#22d3ee;background:#020617;padding:3px 6px;border-radius:4px;margin-right:8px}
.mark{font-weight:bold;color:#22d3ee}
.footer{margin-top:12px;padding:10px;background:rgba(34,211,238,0.1);border:1px solid rgba(34,211,238,0.3);border-radius:8px;text-align:center;font-size:13px;color:#22d3ee}
.cpp{margin-top:10px;font-size:10px;color:#475569;text-align:center}
</style>
</head>
<body>
<div class="card">
<div class="header">
<h2>STUDENT_ARRAY[100]</h2>
<span>C++ ARRAY IMPLEMENTATION • INDEX BASED</span>
</div>

<div class="inputs">
<input id="sname" placeholder="Student name e.g. Kwame">
<input id="score" type="number" placeholder="Score">
</div>
<button class="main-btn" onclick="pushArray()">PUSH TO ARRAY → arr[size++]</button>

<div class="controls">
<button onclick="traverse()">TRAVERSE</button>
<button onclick="calculate()">AVG</button>
<button onclick="findMax()">MAX()</button>
<button onclick="bubbleSort()">SORT()</button>
</div>

<div class="array-box" id="box">
<div style="text-align:center;color:#334155;margin-top:30px;font-size:13px">array empty → size = 0</div>
</div>

<div class="footer" id="msg">System Ready. Array declared as string names[100], int marks[100]</div>
<div class="cpp">for(i=0; i&lt;n; i++) { cout << arr[i]; } // Real C++ array logic</div>
</div>

<script>
let A=[], B=[];
function update(){
let box=document.getElementById('box');
if(A.length==0){box.innerHTML='<div style="text-align:center;color:#334155;margin-top:30px;font-size:13px">array empty → size = 0</div>';return;}
box.innerHTML=A.map((n,i)=>`<div class="item"><div><span class="index">[${i}]</span>${n}</div><div class="mark">${B[i]}</div></div>`).join('');
}
function pushArray(){
let n=document.getElementById('sname').value.trim();
let m=parseInt(document.getElementById('score').value);
if(!n||isNaN(m))return msg('ERROR: Enter name & score');
A.push(n); B.push(m);
document.getElementById('sname').value=''; document.getElementById('score').value='';
update(); msg(`arr[${A.length-1}] = ${n} | size = ${A.length} | PUSH SUCCESS`);
}
function traverse(){update(); msg(`TRAVERSED ${A.length} elements | for loop O(n)`);}
function calculate(){if(!B.length)return;let sum=B.reduce((a,b)=>a+b,0);msg(`Average = ${(sum/B.length).toFixed(1)} | Total = ${sum} | n = ${B.length}`);}
function findMax(){if(!B.length)return;let max=Math.max(...B),i=B.indexOf(max);msg(`MAX = arr[${i}] = ${A[i]} (${max}) | Linear search`);}
function bubbleSort(){if(A.length<2)return;for(let i=0;i<B.length;i++)for(let j=0;j<B.length-1;j++)if(B[j]<B[j+1]){[B[j],B[j+1]]=[B[j+1],B[j]];[A[j],A[j+1]]=[A[j+1],A[j]]}update();msg(`Sorted DESC using Bubble Sort O(n²) | Array reordered`);}
function msg(t){document.getElementById('msg').innerText=t;}
</script>
</body>
</html>
