$(document).ready(function(){ // â �ε�� ���ÿ� ����˴ϴ�.
  $('.mainpic').bxSlider( {
    mode: 'horizontal',// ���� ���� ���� �����̵�
    speed: 1000,        // �̵� �ӵ��� ����(�������� �������ϴ�.)
    pager: false,      // ���� ��ġ ����¡ ǥ�� ���� ����
    moveSlides: 1,     // �����̵� �̵��� ����
    slideMargin: 0,    // �����̵尣�� ����
    auto: true,        // �ڵ� ���� ����
    autoHover: true,   // ���콺 ȣ���� ���� ����
    controls: true,    // ���� ���� ��ư ���� ����
    responsive :false, // �ڵ� ũ������ ��� ����
    slideWidth: 906,   // �����̵��� ũ��
    adaptiveHeight :false, // �ڵ� ���� ����
    infiniteLoop :true, // ���� �ݺ�(���� �̵�)
    minSlides: 1, // �ּ� �����̵� ���� ����
    maxSlides: 10 // �ִ� �����̵� ���� ����
    });
});


function moveTop() {
  window.scrollTo({top:0, left:0, behavior:'smooth'}); // ������ 0, �¿��� 0 ��ġ�� smooth�ɼ��� ����Ͽ� �̵��մϴ�.
}

function submitted() {
  alert("submitted"); // submitted �˸�â�� ���ϴ�.
}

var bgcolor = 0;
function nightmode() { // �߰���忡 �����ϴ� �Լ��Դϴ�.
  if (bgcolor == 0) { // bgcolor�� �⺻���� 0�϶�
    document.body.style.backgroundColor = 'gray'; // ��ü ������
    document.getElementById("credit").style.color = 'black'; // Ǫ���� ��
    document.getElementById("credit").style.backgroundColor = 'dimgray'; // Ǫ���� ����
    document.getElementById("hor").style.borderRight = '2px solid black'; // Ǫ���� �ٴ� �� ������ �����ϰ�
    for(var i=0; i<7; i++) {
      document.getElementById("footermenu" + i).style.color = 'black'; // Ǫ���� �޴����� for���� �̿��� ��� �������ݴϴ�.
    }
    bgcolor++;
  }
  else{
    document.body.style.backgroundColor = 'lightgray'; // ���� if���� �Ȱ��� ������ �۵��մϴ�.
    document.getElementById("credit").style.color = 'dimgray';
    document.getElementById("credit").style.backgroundColor = 'silver';
    document.getElementById("hor").style.borderRight = '2px solid dimgray';
    for(var i=0; i<7; i++) {
      document.getElementById("footermenu" + i).style.color = 'dimgray';
    }
    bgcolor--;
  }
}


function CloseModal(){ // ���â�� �ݴ� ��ư�Դϴ�.
  var CloseModal = document.querySelector(".container"); //.container Ŭ������ ã�� CloseModal�� �����ϰ�
  CloseModal.style.display ="none"; // �ش� Ŭ������ ������ �ʰ� �մϴ�.
}
function Checked() {
  var CloseModal = document.querySelector(".container"); // ���� �����մϴ�.
  CloseModal.style.display ="none";
}